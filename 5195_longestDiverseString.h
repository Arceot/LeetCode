#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//有点贪心的感觉
class Solution {
public:
	//不要cmp也能排，默认按照第一个排的？
	static bool cmp(pair<int, char>& a, pair<int, char>& b)
	{
		return a.first > b.first;
	}
	string longestDiverseString(int a, int b, int c) {
		vector<pair<int, char>> vec;
		int append_len = 0;
		string ret_str = "";
		vec.push_back(make_pair(a, 'a'));
		vec.push_back(make_pair(b, 'b'));
		vec.push_back(make_pair(c, 'c'));
		sort(vec.rbegin(), vec.rend());
		
		append_len = min(vec[0].first, 2);
		ret_str.append(append_len, vec[0].second);
		vec[0].first -= append_len;

		sort(vec.begin(), vec.end(), cmp);
		while (vec[1].first>0)
		{
			if (vec[0].second == ret_str.back())
			{
				ret_str += vec[1].second;
				vec[1].first--;
			}
			if (vec[0].second != ret_str.back())
			{
				append_len = min(vec[0].first, 2);
				ret_str.append(append_len, vec[0].second);
				vec[0].first -= append_len;
			}
			sort(vec.begin(), vec.end(), cmp);
		}
		//剩余的放进来
		//cout << ret_str << endl;
		if (vec[0].first>0)
		{
			if (ret_str.back() != vec[0].second)//要放入的和结尾不相等，直接放
			{
				append_len = min(vec[0].first, 2);
				ret_str.append(append_len, vec[0].second);
			}
			else//要放入的和结尾相等
			{
				if (ret_str.size() >= 2 && ret_str.back() == ret_str[ret_str.size() - 2])//结尾的两个字符相等
				{
					return ret_str;
				}
				ret_str.push_back(vec[0].second);
			}
		}
		return ret_str;
	}
};
