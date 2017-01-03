// BigIntMultiply.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

void BigIntMultiply(const std::string& a, const std::string& b, std::vector<int>& result)
{
	if (!a.empty() && !b.empty())
	{
		if (result.size() < a.size() + b.size())
			result.resize(a.size() + b.size());
		
		result[0] = 0;

		for (std::size_t i = 0; i < a.size(); i++)
		{
			std::size_t k = i + 1;
			for (std::size_t j = 0; j < b.size(); j++)
			{
				if (a[i] >= '0' && a[i] <= '9'
					&& b[j] >= '0' && b[j] <= '9')
				{
					result[k++] += (a[i] - '0') * (b[j] - '0');
				}
				else
				{
					std::cout << "Invalid input!" << std::endl;
					exit(1);
				}
			}
		}

		for (std::size_t k = result.size() - 1; k > 0; k--)
		{
			result[k - 1] += result[k] / 10;
			result[k] = result[k] % 10;				
		}
	}
}

void Test(const std::string& a, const std::string& b, const long long c, const long long d)
{
	std::vector<int> result;
	BigIntMultiply(a, b, result);
	for (std::size_t i = 0; i < result.size(); i++)
	{
		if (i == 0)
		{
			if (result[i] != 0)
				std::cout << result[i];
		}
		else
		{
			std::cout << result[i];
		}
	}
	std::cout << std::endl;
	std::cout << c*d << std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test("1234", "123", 1234, 123);

	Test("12345", "1234", 12345, 1234);

	Test("54321", "54321", 54321, 54321);

	Test("231456879", "324581729", 231456879, 324581729);
	
	return 0;
}

