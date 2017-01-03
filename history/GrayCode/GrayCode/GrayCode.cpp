// GrayCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using std::vector;
using std::string;

vector<string> GrayCode(int n)
{
	vector<string> graycode((int)pow(2, n));

	if (n == 1)
	{
		graycode[0] = "0";
		graycode[1] = "1";
		return graycode;
	}

	vector<string> last = GrayCode(n-1);

	for (int i = 0; i < last.size(); i++)
	{
		graycode[i] = "0" + last[i];
		graycode[graycode.size() - 1 - i] = "1" + last[i];
	}

	return graycode;
}

string Num2Binary(int num, int bitNum);

void PrintGrayCode(int bitNum)
{
	int codesNum = (int)pow(2, bitNum);
	int graycode;
	for (int i = 0; i < codesNum; i++)
	{
		graycode = (i >> 1) ^ i;
		std::cout << Num2Binary(graycode, bitNum) << std::endl;
	}
}

string Num2Binary(int num, int bitNum)
{
	string ret;
	for (int i = bitNum - 1; i >= 0; i--)
	{
		ret += (num >> i) & 1 ? "1" : "0";
	}
	return ret;
}

void Test(int n)
{
	vector<string> graycode = GrayCode(n);
	std::cout << n << " bits of graycodes: " << std::endl;
	for (int i = 0; i < graycode.size(); i++)
		std::cout << graycode[i] << std::endl;

	std::cout << n << "bits of graycodes using another method:" << std::endl;
	PrintGrayCode(n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(5);
	return 0;
}

