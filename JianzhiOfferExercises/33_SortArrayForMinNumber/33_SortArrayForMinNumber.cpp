// 33_SortArrayForMinNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*
using std::string;
using std::vector;
using std::to_string;
using std::cout;
using std::endl;*/
using namespace std;

string MinNumber(vector<int>& number)
{
	vector<string> arr;
	for (const auto& i : number)
		arr.push_back(to_string(i));

	sort(begin(arr), end(arr), [](string& s1, string& s2) {return s1 + s2 < s2 + s1; });

	string res;
	for (const auto& i : arr)
		res += i;

	return res;
}

void Test(const string& testname, vector<int>& number, const string& expected)
{
	cout << testname << " begins:" << endl;
	cout << "Expected result is: " << expected << endl;
	cout << "Actual result is: " << MinNumber(number) << endl;
}

void Test1()
{
	vector<int> number = {3,5,1,4,2};
	Test("Test1", number, "12345");
}

void Test2()
{
	vector<int> number = {3,32,321};
	Test("Test2", number, "321323");
}

void Test3()
{
	vector<int> number = {3,323,32123};
	Test("Test3", number, "321233233");
}

void Test4()
{
	vector<int> number = { 1, 11, 111 };
	Test("Test4", number, "111111");
}

void Test5()
{
	vector<int> number = {321};
	Test("Test5", number, "321");
}

void Test6()
{
	vector<int> number;
	Test("Test6", number, "");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	return 0;
}

