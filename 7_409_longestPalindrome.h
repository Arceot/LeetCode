#include <string>
using namespace std;

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