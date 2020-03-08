//3 438 76���������ƶ��ǻ�������
#include <string>
using namespace std;

//˫ָ�� �������� ����Ƶ��ļ��һЩ
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//�п�
		if (s.size()==0) 
			return 0;

		int char_map[128] = {0};
		int maxlen = 0,left = 0;
		for (int i = 0; i < s.size();i++)
		{
			char_map[s[i]]++;
			//�����ظ��ľͳ�������left
			while (left<i && char_map[s[i]]>1)
			{
				char_map[s[left]]--;
				left++;
			}
			//����������ƶ���ʣ�µĿ϶�û���ظ�����
			if (i - left+1>maxlen)
			{
				maxlen = i - left+1;
			}
		}
		return maxlen;
	}
};


//��Ƶ���
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;//ͷָ��
		int char_map[128] = { 0 };//��¼�ַ����ֵĴ���
		string word = "";//��¼begin��i���ַ���
		int result=0;
		for (int i = 0; i < s.length();i++)
		{
			char_map[s[i]]++;//s[i]�ַ����ֵĴ���+1
			if (char_map[s[i]]<=1)//û���ظ�
			{
				word += s[i];
				if (word.length()>result)//result���ڼ�¼�word�ĳ���
				{
					result = word.length();
				}
			}
			else//���ظ�
			{
				//��beginָ������������ظ��ַ��ĺ�һ���ַ�
				while (char_map[s[i]]>1)
				{
					char_map[s[begin]]--;//ע������s[begin]����begin
					begin++;
				}
				word = "";
				word = s.substr(begin, i - begin + 1);//����дҲ����

			}
		}
		return result;
	}
};