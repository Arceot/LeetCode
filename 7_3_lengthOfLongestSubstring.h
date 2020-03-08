//3 438 76三道题类似都是滑动窗口
#include <string>
using namespace std;

//双指针 滑动窗口 比视频里的简洁一些
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//判空
		if (s.size()==0) 
			return 0;

		int char_map[128] = {0};
		int maxlen = 0,left = 0;
		for (int i = 0; i < s.size();i++)
		{
			char_map[s[i]]++;
			//遇到重复的就尝试左移left
			while (left<i && char_map[s[i]]>1)
			{
				char_map[s[left]]--;
				left++;
			}
			//经过上面的移动，剩下的肯定没有重复的了
			if (i - left+1>maxlen)
			{
				maxlen = i - left+1;
			}
		}
		return maxlen;
	}
};


//视频里的
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;//头指针
		int char_map[128] = { 0 };//记录字符出现的次数
		string word = "";//记录begin到i的字符串
		int result=0;
		for (int i = 0; i < s.length();i++)
		{
			char_map[s[i]]++;//s[i]字符出现的次数+1
			if (char_map[s[i]]<=1)//没有重复
			{
				word += s[i];
				if (word.length()>result)//result用于记录最长word的长度
				{
					result = word.length();
				}
			}
			else//有重复
			{
				//将begin指针后移至出现重复字符的后一个字符
				while (char_map[s[i]]>1)
				{
					char_map[s[begin]]--;//注意是是s[begin]不是begin
					begin++;
				}
				word = "";
				word = s.substr(begin, i - begin + 1);//这样写也可以

			}
		}
		return result;
	}
};