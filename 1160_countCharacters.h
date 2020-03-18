#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;
//�õ�map�������ڴ����Ĵ󣬺�������������,map�ײ����������Һ�ʱO(log n)
class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		unordered_map<char, int> cmap;
		for (int i = 0; i < chars.size();i++)
		{
			cmap[chars[i]]++;
		}
		int cnt = 0;
		for (int i = 0; i < words.size();i++)
		{
			unordered_map<char, int> tmp_cmp(cmap); 
			for (int j = 0; j < words[i].size();j++)
			{
				if (tmp_cmp.find(words[i][j])==tmp_cmp.end() || tmp_cmp[words[i][j]] == 0)
				{
					break;
				}
				tmp_cmp[words[i][j]]--;
				if (j == words[i].size()-1)
				{
					cnt += words[i].size();
				}
			}
		}
		return cnt;
	}
};

//���������ԣ�����ʱ����ڴ����Ľ��ͺܶ�
class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int cmap[128] = {0};
		for (int i = 0; i < chars.size(); i++)
		{
			cmap[chars[i]]++;
		}
		int cnt = 0;
		int tmp_cmap[128] = {0};
		for (int i = 0; i < words.size(); i++)
		{
			memcpy(tmp_cmap,cmap,sizeof(tmp_cmap));//memcpy��cmap���鸴�Ƶ�tmp_cmap������
			for (int j = 0; j < words[i].size(); j++)
			{
				if (tmp_cmap[words[i][j]] == 0)
				{
					break;
				}
				tmp_cmap[words[i][j]]--;
				if (j == words[i].size() - 1)
				{
					cnt += words[i].size();
				}
			}
		}
		return cnt;
	}
};