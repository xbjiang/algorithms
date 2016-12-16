#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) == map.end())
            {
                map.insert({ tmp, vector<string>() });
            }
            map[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto& item : map)
            ret.push_back(item.second);
        return ret;
    };
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ret = s.groupAnagrams(strs);
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j].c_str() << " ";
        }
        cout << endl;
    }

}