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
    char buffer[] = "This is *a test";
	vector<string> ret;
	split(buffer, " *", ret);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
	cout << buffer << endl;

	string buffer2 = "This is  another test!";
	ret.clear();
	split(buffer2, ' ', ret, false);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
	cout << buffer2 << endl;
}