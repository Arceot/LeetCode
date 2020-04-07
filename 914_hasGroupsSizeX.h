#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

// 暴力枚举
//首先统计所有数字出现的次数
//判断所有次数是否包含有共同的约数
class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> imap;
		for (int i = 0; i < deck.size(); i++)
		{
			imap[deck[i]]++;
		}
		vector<int> cnt_vec;
		for (auto it : imap)
		{
			cnt_vec.push_back(it.second);
		}
		sort(cnt_vec.begin(), cnt_vec.end());
		for (int i = 2; i <= cnt_vec[0]; i++)//遍历从2开始到vec中最小值的约数
		{
			if (deck.size() % i != 0)
			{
				continue;
			}
			for (int j = 0; j < cnt_vec.size(); j++)//遍历cnt_vec中的值
			{
				if (cnt_vec[j] % i != 0)
				{
					break;
				}
				if (j==cnt_vec.size()-1)
				{
					return true;
				}
			}
		}
		return false;
	}
};

//最大公约数法 
//求最大公约数的方法还需要消化下
class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		int cnt[10000] = { 0 };
		for (int i:deck) cnt[i]++;

		int maxg = 0;
		for (int i:cnt) maxg = gcd(i,maxg);
		return maxg >= 2;
	}
	int gcd(int a,int b)
	{
		if (a==0)
			return b;
		else
			return gcd(b%a, a);
	}
};