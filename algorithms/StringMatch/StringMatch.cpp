#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int brutal_match(char* s, char* p)
{
    int lenS = strlen(s);
    int lenP = strlen(p);
    int i = 0;
    int j = 0;
    
    while (i < lenS && j < lenP)
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
    if (j == lenP) 
        return i - j;
    else 
        return -1;
}

int main(int argc, char* argv[])
{
    char s[] = "abc def ghi";
    char p[] = "def";
    printf("%d\n", brutal_match(s,p));
}