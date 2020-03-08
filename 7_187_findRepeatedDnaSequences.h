#include <map>
#include <vector>
#include <string>
using namespace std;

//由前向后遍历
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		string word = "";
		map<string, int> string_map;//<字符串，字符串数量>的映射
		vector<string> result;
		//cout << s.length()<<endl;
		if (s.length()<=10)
		{
			return result;
		}
		for (int i = 0; i <= s.length()-10;i++)
		{
			word = s.substr(i, 10);//复制从i开始，共计10个字符
			string_map[word]++;
			word = "";
		}
		for (auto it = string_map.begin(); it != string_map.end();it++)
		{
			if (it->second>1)
			{
				result.push_back(it->first);
			}
		}
		return result;
		
	}
};