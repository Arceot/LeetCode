#include <map>
#include <vector>
#include <string>
using namespace std;

//��ǰ������
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		string word = "";
		map<string, int> string_map;//<�ַ������ַ�������>��ӳ��
		vector<string> result;
		//cout << s.length()<<endl;
		if (s.length()<=10)
		{
			return result;
		}
		for (int i = 0; i <= s.length()-10;i++)
		{
			word = s.substr(i, 10);//���ƴ�i��ʼ������10���ַ�
			string_map[word]++;
			word = "";
		}
		for (auto it = string_map.begin(); it != string_map.end();it++)
		{
			if (it->second>1)
			{
				result.push_back(it->first);
			}
		}
		return result;
		
	}
};