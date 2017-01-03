// LongestPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::min;

// A Dynamic Programming solution
string LongestPalindromeDP(string s)
{
	int n = s.length();
	int longestBegin = 0;
	int maxLen = 1;
	bool table[1000][1000] = {false};

	for (int i = 0; i < n; i++) {
		table[i][i] = true;
		longestBegin = i;
		maxLen = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
			longestBegin = i;
			maxLen = 2;
		}
	}

	for (int len = 3; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			if (s[i] == s[j] && table[i + 1][j - 1]) {
				table[i][j] = true;
				longestBegin = i;
				maxLen = len;
			}
		}
	}

	return s.substr(longestBegin, maxLen);
}

//An improved solution with O(1) space
string ExpandAroundCenter(string s, int c1, int c2)
{
	int n = s.length();
	int l = c1, r = c2;
	while (l >= 0 && r < n && s[l] == s[r]) {
		l--;
		r++;
	}
	 
	return s.substr(l+1, r-l-1);
}

string LongestPalindromeSimple(string s)
{
	int n = s.length();
	if (n == 0) return "";
	string longest = s.substr(0, 1);
	
	for (int i = 0; i < n; i++) {
		string p1 = ExpandAroundCenter(s, i, i);
		if (p1.length() > longest.length())
			longest = p1;

		string p2 = ExpandAroundCenter(s, i, i+1);
		if (p2.length() > longest.length())
			longest = p2;
	}

	return longest;
}

//An O(n) solution: Manacher's algorithm
string PreProcess(string s)
{
	int n = s.length();
	if (n == 0) return "^$";
	string ret = "^";
	for (int i = 0; i < n; i++) {
		ret += "#" + s.substr(i, 1);
	}

	ret += "#$";
	return ret;
}

string Manacher(string s)
{
	string T = PreProcess(s);
	int n = T.length();

	int C = 0, R = 0;
	int* P = new int[n];

	for (int i = 1; i < n-1; i++) {
		int i_mirror = 2 * C - i;
		P[i] = R > i ? min(P[i_mirror], R - i) : 0;

		while (T[i + P[i] + 1] == T[i - P[i] - 1])
			P[i]++;

		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	int centerIndex = 0;
	int maxLen = 0;
	for (int i = 1; i < n-1; i++) {
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	}
	delete[] P;
	
	return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

void Test(string s)
{
	cout << "The longest palindrome of " << s
		<< " is: " << LongestPalindromeDP(s) << endl;

	cout << "The longest palindrome of " << s
		<< " is: " << LongestPalindromeSimple(s) << endl;

	cout << "The longest palindrome of " << s
		<< " is: " << Manacher(s) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test("aba");
	Test("abc");
	Test("ababashit");
	return 0;
}

