#include <map>
#include <string>
#include <vector>
using namespace std;
//�Ƚ�str��⵽vector��
//�ж�pattern�ĳ�����vec�ĳ����Ƿ����
//��������used���ڼ�¼pattern�е���ĸ�Ƿ�ʹ�ù��������ص�
//����string��char��map���������Ƚ�
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		//��str������vector��
		vector<string> str_vec;
		string word = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				str_vec.push_back(word);
				word = "";
				i++;
			}
			word += str[i];
			//str�����һ����ĸʱ����word����
			if (i == str.length() - 1)
				str_vec.push_back(word);
		}

		//���Ȳ�һ�£�����false
		if (pattern.length() != str_vec.size())
		{
			return false;
		}
		//��ǰ������������map
		char used[128] = { 0 };//��¼��ĸ�Ƿ�ʹ�ã�������е�˫���Ӧ��ASCIIһ��128��
		map<string, char> s_c_map;//stringΪkey��charΪvalue
		for (int i = 0; i < str_vec.size(); i++)
		{
			//�ҵ���
			if (s_c_map.find(str_vec[i]) != s_c_map.end())
			{
				//û��Ӧ��
				if (s_c_map[str_vec[i]] != pattern[i])
				{
					return false;
				}
			}
			//û�ҵ�
			if (s_c_map.find(str_vec[i]) == s_c_map.end())
			{
				//��ĸ��ʹ�ù�
				if (used[pattern[i]] == 1)
				{
					return false;
				}
				//��ĸû�б�ʹ�ù�
				if (used[pattern[i]]==0)
				{
					//����ӳ��
					s_c_map[str_vec[i]] = pattern[i];
					//��1����ʾ��ĸ��ʹ���ˣ����治�ܲ��������ַ����������ַ��Ķ�Ӧ�ˣ�
					//����������˫�����ӵĶ�Ӧ����
					used[pattern[i]] = 1;
				}
			}
		}
		return true;
	}
};