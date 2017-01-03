// LongestCommonSubsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum direction {Up = 0, Left, UpLeft};

void lcsCore(const string& str1, const string& str2,
	vector<vector<int>>& recordTable)
{
	int m = str1.length();
	int n = str2.length();

	vector<vector<int>> lenTable(m+1, vector<int>(n+1, 0));

/*
	for (int i = 0; i <= m; i++) {
		lenTable[i][0] = 0;
	}

	for (int j = 0; j <= n; j++) {
		lenTable[0][j];
	}*/

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lenTable[i][j] = lenTable[i - 1][j - 1] + 1;
				recordTable[i - 1][j - 1] = UpLeft;
			} 
			else if (lenTable[i - 1][j] > lenTable[i][j - 1]) {
				lenTable[i][j] = lenTable[i - 1][j];
				recordTable[i - 1][j - 1] = Up;
			}
			else {
				lenTable[i][j] = lenTable[i][j - 1];
				recordTable[i - 1][j - 1] = Left;
			}
		}
	}
}

void getlcs(const string& str1, const vector<vector<int>>& recordTable,
			string& ret, int i, int j)
{
	if (i < 0 || j < 0)
		return;

	if (recordTable[i][j] == UpLeft)
	{
		getlcs(str1, recordTable, ret, i - 1, j - 1);
		ret += str1.substr(i, 1);
	}
	else if (recordTable[i][j] == Up)
		getlcs(str1, recordTable, ret, i - 1, j);
	else
		getlcs(str1, recordTable, ret, i, j-1);
}

string lcs(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();

	vector<vector<int>> recordTable(m, vector<int>(n));

	lcsCore(str1, str2, recordTable);

	string ret;
	getlcs(str1, recordTable, ret, m-1, n-1);

	return ret;
}

void Test(const string& str1, const string& str2)
{
	cout << "The first string is: " << str1 << endl;
	cout << "The second string is: " << str2 << endl;
	cout << "The longest common subsequence is: "
		<< lcs(str1, str2) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str1 = "ABCBDAB";
	string str2 = "BDCABA";
	Test(str1, str2);
	return 0;
}

