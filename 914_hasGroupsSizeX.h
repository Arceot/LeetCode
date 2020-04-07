#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

// ����ö��
//����ͳ���������ֳ��ֵĴ���
//�ж����д����Ƿ�����й�ͬ��Լ��
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
		for (int i = 2; i <= cnt_vec[0]; i++)//������2��ʼ��vec����Сֵ��Լ��
		{
			if (deck.size() % i != 0)
			{
				continue;
			}
			for (int j = 0; j < cnt_vec.size(); j++)//����cnt_vec�е�ֵ
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

//���Լ���� 
//�����Լ���ķ�������Ҫ������
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