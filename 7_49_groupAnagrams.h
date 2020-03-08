#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		map<string,vector<string>> str_map;
		for (int i = 0; i < strs.size();i++)
		{
			string tmp_str=strs[i];
			sort(tmp_str.begin(), tmp_str.end());
			str_map[tmp_str].push_back(strs[i]);
		}
		//遍历map将结果插入result中
		//map<string, vector<string>>::iterator it;
		//for (it = str_map.begin(); it != str_map.end();it++)
		//{
		//	result.push_back(it->second);
		//}
		
		//for (auto& it:str_map)
		//{
		//	result.push_back(it.second);
		//}
		for (auto it = str_map.begin(); it != str_map.end();it++)
		{
			result.push_back(it->second);
		}
		return result;
	}
};