/*
* split a string by any delimiter
*/

#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// strtok is not thread safe, and change buffer
void split(char* buffer, const char* delim, vector<string>& ret)
{
    char* token = strtok(buffer, delim);
    while (token != NULL)
    {
        ret.push_back(token);
        token = strtok(NULL, delim);
    }
}

vector<string>& split(const string& str,const char delim, vector<string>& ret, bool skip_empty = true)
{
    istringstream iss(str);
    string item;
    while (getline(iss, item, delim))
    {
        if (skip_empty && item.empty()) continue;
        else ret.push_back(item);
    }
    return ret;
}

int main()
{
    char* buffer = "This is a test";
    cout << buffer << endl;
}