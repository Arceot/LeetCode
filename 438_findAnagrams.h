//3 438 76三道题类似都是滑动窗口
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> vec;
		int char_map[128] = {0};
		int count = 0, left = 0;

		//记录还有多少没找到
		for (int i = 0; i < p.size();i++)
		{
			char_map[p[i]]++;
		}
		for (int i = 0; i < s.size();i++)
		{
			char_map[s[i]]--;
			if (char_map[s[i]]>=0)
			{
				count++;
			}
			while (count==p.size())
			{
				if (count==i-left+1)
				{
					vec.push_back(left);
				}
				char_map[s[left]]++;
				if (char_map[s[left]]>0)
				{
					count--;
				}
				left++;
			}
		}
		return vec;
	}
};