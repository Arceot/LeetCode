#include <string>
#include <map>
#include <vector>
using namespace std;
//https://leetcode-cn.com/problems/minimum-window-substring/solution/zhe-dao-ti-de-nan-dian-fen-xi-by-wang-yan-19/
//https://leetcode-cn.com/problems/minimum-window-substring/solution/c-unordered_map-8ms-9847-by-karlzhang/
//具体思路参考上面的链接
//这种模拟音量上下浮动的方法具有借鉴性
//注意t中可能有重复的字符
//双指针，left和i，右移


class Solution {
public:
	string minWindow(string s, string t) {
		int t_char_map[128] = { 0 };
		int left = 0, start = left;
		//给minlen赋一个区间中不可能达到的值，类似于做一个标记
		int minlen = s.size() + 1;
		//count用来判断当前窗口是否满足要求
		int count = 0;
		for (int i = 0; i < t.size(); i++)
		{
			//初始化map
			t_char_map[t[i]]++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			t_char_map[s[i]]--;
			//说明s当前的char命中了t中的某个char
			if (t_char_map[s[i]] >= 0)
			{
				count++;
			}

			//当count == t.size()时说明找齐了，
			//当前窗口符合要求
			while (count == t.size())//找齐了
			{
				//存储最先窗口的起始位置和长度，
				//因为substr需要这两个元素
				if (i - left + 1 <= minlen)
				{
					minlen = i - left + 1;
					start = left;
				}
				//准备移动left
				t_char_map[s[left]]++;
				//此时t_char_map[s[left]]要么为0，要么为负
				/*
				这时两种情况：
				1.s[left]不在不在t中
				2.s[left]在t中，但是窗口中s[left]的数量大于t中s[left]的数量
				*/
				//当(t_char_map[s[left]] > 0时，说明等会左边去掉的是t中的字符
				//且此时窗口中s[left]的数量和t中s[left]的数量相等，
				//且说明去掉s[left]后这个窗口已经不符合条件啦
				if (t_char_map[s[left]] > 0)
				{
					count--;
				}
				left++;
			}
		}
		return minlen == s.size() + 1 ? "" : s.substr(start, minlen);
	}
};


////视频中的方法，思路可以，但是太耗时间了。在covered那里耗时
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string ret = "";
//		int begin = 0;
//		const int MAX_LEN = 128;
//		int s_char_map[MAX_LEN] = { 0 };//记录s中begin到i之间字符出现的次数
//		int t_char_map[MAX_LEN] = { 0 };//记录t中字符出现的次数
//		for (int i = 0; i < t.length(); i++)
//			t_char_map[t[i]]++;
//
//		for (int i = 0; i < s.length(); i++)
//		{
//			s_char_map[s[i]]++;
//
//			//若begin小于i，尽量移动begin
//			while (begin<i)
//			{
//				if (t.find(s[begin]) == -1)//s[begin]不在t中
//				{
//					s_char_map[s[begin]]--;
//					begin++;
//				}
//				//s[begin]在t中，且当前子串中s[begin]的数量比t中s[begin]的数目大
//				else if (s_char_map[s[begin]]>t_char_map[s[begin]])
//				{
//					s_char_map[s[begin]]--;
//					begin++;
//				}
//				else
//					break;
//			}
//
//			//判断t中的字符是否都在word中出现过,且数量相等
//			if (s_char_map[s[begin]]==t_char_map[s[begin]]
//				&&covered(s_char_map, t_char_map, t))
//			{
//				if (ret == "" || (i - begin + 1) < ret.length())
//				{
//					ret = s.substr(begin, i - begin + 1);
//				}
//				//不加这两句话得话会超时，即使加上了，时间也会很长，所以这种方法的思路可以。但是太耗时了。
//				s_char_map[s[begin]]--;//注意是s[begin],别误写成了begin
//				begin++;
//			}
//		}
//		return ret;
//	}
//private:
//	bool covered(int s_char_map[], int t_char_map[], string t)
//	{
//		for (int i = 0; i < t.length(); i++)
//		{
//			if (s_char_map[t[i]] < t_char_map[t[i]])//注意这里是小于
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};