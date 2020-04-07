#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

////自己想的方法，总是超时
////遍历words里面的单词，用一vec存储遍历的字符串中的父串
//class Solution {
//public:
//	int minimumLengthEncoding(vector<string>& words) {
//		vector<string> vec;
//		for (int i = 0; i < words.size(); i++)//遍历字符串数组
//		{
//			int substr_flag = 0;
//			for (int j = 0; j<vec.size(); j++)
//			{
//				if (is_substr(vec[j], words[i]))//是子串
//				{
//					substr_flag = 1;
//					if (words[i].size() > vec[j].size())//新串长
//					{
//						vec[j] = words[i];
//					}
//					break;
//				}
//			}
//			if (substr_flag == 0)//在里面没找到是谁的子串
//			{
//				vec.push_back(words[i]);
//			}
//		}
//		int cnt = 0;
//		for (auto it : vec)//遍历map
//		{
//			cnt += it.size() + 1;
//		}
//		return cnt;
//	}
//
//	//判断是不是子串
//	bool is_substr(string str1, string str2)
//	{
//		//使 str1长 str2短
//		string tmp_str = "";
//		if (str1.length() < str2.length())
//		{
//			tmp_str = str1;
//			str1 = str2;
//			str2 = tmp_str;
//		}
//		int len1 = str1.length();//长
//		int len2 = str2.length();//短
//		for (int i = 0; i < len2; i++)
//		{
//			if (str2[i] != str1[i + (len1 - len2)])
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};


//看别人的一种方法
//先将word里面的字符串倒过来，再将Wword里面的单词排序，
//然后逐个向后遍历，只需要比较相邻的连个单词就行了
//重点是能想到这种方法，其次是知道reverse 和 sort 的用法
//auto 加不加 & 区别很大，不加算的不对，需要查查为什么
class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		for (auto& s:words)
		{
			reverse(s.begin(), s.end());//翻转每一个单词
		}
		sort(words.begin(), words.end());//按字母排序
		int ret = 0;
		//留最后一个单词不访问，避免越界，也可以提前在Word后面补一个单词，
		//但是那样就修改了word，应该尽量不要修改传入的参数
		for (int i = 0; i < words.size()-1;i++)
		{
			if (words[i] == words[i + 1].substr(0, words[i].size()))
			{
				continue;
			}
			ret += words[i].size() + 1;
		}
		return ret+words.back().size()+1;//最后一组最长的单词肯定是最后一个，把它加进去
	}
};
