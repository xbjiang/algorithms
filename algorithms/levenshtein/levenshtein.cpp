#include <iostream>
#include <string>
#include <vector>
using namespace std;

// find the minimum in three numbers
template <typename T>
T Min(T a, T b, T c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= c)
        return b;
    return c;
}

int levenshteinDP(const string& str1, const string& str2)
{
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (size_t i = 1; i <= len1; i++)
        dp[i][0] = i;
    for (size_t j = 1; j <= len2; j++)
        dp[0][j] = j;

    for (size_t i = 1; i <= len1; i++)
    {
        for (size_t j = 1; j <= len2; j++)
        {
            int cost = 0;
            if (str1[i - 1] != str2[j - 1])
                cost = 1;
            dp[i][j] = Min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+cost);
        }
    }
    return dp[len1][len2];
}

int lenvenshteinTwoRows(const string& str1, const string& str2)
{
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    vector<int> vec1(len2+1, 0);
    vector<int> vec2(len2+1, 0);
    for (size_t i = 1; i <= len2; i++)
        vec1[i] = i;
    
    for (size_t i = 1; i <= len1; i++)
    {
        vec2[0] = i;
        for (size_t j = 1; j <= len2; j++)
        {
            int cost = 0;
            if (str1[i-1] != str2[j-1])
                cost = 1;
            vec2[j] = Min(vec1[j] + 1, vec2[j-1] + 1, vec1[j-1] + cost);
        }
        vec1.swap(vec2);
    }
    return vec1[len2];
}

int main(int argc, char* argv[])
{
    cout << levenshteinDP("abcde", "fghij") << endl;
    cout << lenvenshteinTwoRows("abcde", "fghij") << endl;
}