#include <stdio.h>
#include <string.h>

int brutal_match(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0; 
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

void get_next(char* p, int next[])
{
	int pLen = strlen(p);
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int kmp_match(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int* next = new int[pLen];
	get_next(p, next);
	int i = 0; 
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j]; 
		}
	}
	delete[] next;
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main(int argc, char* argv[])
{
	char* s = "abc def ghij";
	char* p = "def";
	printf("%d\n", kmp_match(s,p));
}