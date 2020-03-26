#include <string>
using namespace std;

//��Ƶ��ķ���
class Solution {
public:
	int longestPalindrome(string s) {
		int char_map[128] = { 0 };//�ַ���ϣ�������±��Ӧascii���е��ַ�
		int flag = 0;//�Ƿ������ĵ���
		int max_length = 0;//�������ĵ�ʱ������������

		for (int i = 0; i < s.length();i++)
		{
			char_map[s[i]]++;//s[i]����ʾASCII�е��ַ�Ҳ��ʾ���Ӧ��ʮ��������
		}
		for (int i = 0; i < 128;i++)
		{
			if (char_map[i]%2==0)//��ż
			{
				max_length += char_map[i];
			}
			else
			{
				max_length += char_map[i] - 1;
				flag = 1;
			}
		}
		return max_length + flag;
	}
};

//�ҵķ��� ���е�ż������-1,����������ټ�1
//��ʵ������Ĵ���һ��
class Solution {
public:
	int longestPalindrome(string s) {
		int cmap[128] = {0};
		for (int i = 0; i < s.size();i++)
		{
			cmap[s[i]]++;
		}
		int maxlen = 0;
		int Odd_flag = 0;
		for (int i = 0; i < 128;i++)
		{
			if (cmap[i]%2==1)//���δ��������ȡ��ż������
			{
				maxlen += cmap[i] - 1;
				Odd_flag = 1;
			}
			else
			{
				maxlen += cmap[i];
			}
		}
		return maxlen + Odd_flag;//����м���������������ôҪ��1
	}
};