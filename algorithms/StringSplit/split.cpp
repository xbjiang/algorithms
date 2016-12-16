/*
* split a string by any delimiter
*/

#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// strtok is not thread safe, and change buffer; it writes '\0' characters in buffer
/*void split(char* buffer, const char* delim, vector<string>& ret)
{
    char* token = strtok(buffer, delim);
    while (token != NULL)
    {
        ret.push_back(token);
        token = strtok(NULL, delim);
    }
}*/

vector<string>& split(const string& str,const char delim, vector<string>& ret, bool skip_empty = true)
{
    istringstream iss(str);
    string item;
    while (getline(iss, item, delim))
    {
        if (skip_empty && item.empty()) continue;
        ret.push_back(item); 
    }
    return ret;
}

vector<string>& split(const string& str, const string& delimeters, vector<string>& ret)
{
    string::size_type pos, prev = 0;
    while ((pos = str.find_first_of(delimeters, prev)) != string::npos)
    {
        if (pos > prev)
        {
            //if (skip_empty && pos - prev == 1) break; // this line is useless, and also wrong for some specific case, i.e., "a,a,a,a,a,a"
            ret.emplace_back(str, prev, pos - prev);
        }
        prev = pos + 1;
    }
    if (prev < str.size()) ret.emplace_back(str, prev, str.size() - prev);
    return ret;
}

int main()
{
    string str("Windows,Linux||,|MacOS All");
    vector<string> ret;
    for (const auto& s : split("a,a,a,a,a,a", ",| ", ret))
        cout << s << endl;
}
