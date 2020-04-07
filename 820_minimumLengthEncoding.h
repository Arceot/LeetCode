#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

////�Լ���ķ��������ǳ�ʱ
////����words����ĵ��ʣ���һvec�洢�������ַ����еĸ���
//class Solution {
//public:
//	int minimumLengthEncoding(vector<string>& words) {
//		vector<string> vec;
//		for (int i = 0; i < words.size(); i++)//�����ַ�������
//		{
//			int substr_flag = 0;
//			for (int j = 0; j<vec.size(); j++)
//			{
//				if (is_substr(vec[j], words[i]))//���Ӵ�
//				{
//					substr_flag = 1;
//					if (words[i].size() > vec[j].size())//�´���
//					{
//						vec[j] = words[i];
//					}
//					break;
//				}
//			}
//			if (substr_flag == 0)//������û�ҵ���˭���Ӵ�
//			{
//				vec.push_back(words[i]);
//			}
//		}
//		int cnt = 0;
//		for (auto it : vec)//����map
//		{
//			cnt += it.size() + 1;
//		}
//		return cnt;
//	}
//
//	//�ж��ǲ����Ӵ�
//	bool is_substr(string str1, string str2)
//	{
//		//ʹ str1�� str2��
//		string tmp_str = "";
//		if (str1.length() < str2.length())
//		{
//			tmp_str = str1;
//			str1 = str2;
//			str2 = tmp_str;
//		}
//		int len1 = str1.length();//��
//		int len2 = str2.length();//��
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


//�����˵�һ�ַ���
//�Ƚ�word������ַ������������ٽ�Wword����ĵ�������
//Ȼ�������������ֻ��Ҫ�Ƚ����ڵ��������ʾ�����
//�ص������뵽���ַ����������֪��reverse �� sort ���÷�
//auto �Ӳ��� & ����ܴ󣬲�����Ĳ��ԣ���Ҫ���Ϊʲô
class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		for (auto& s:words)
		{
			reverse(s.begin(), s.end());//��תÿһ������
		}
		sort(words.begin(), words.end());//����ĸ����
		int ret = 0;
		//�����һ�����ʲ����ʣ�����Խ�磬Ҳ������ǰ��Word���油һ�����ʣ�
		//�����������޸���word��Ӧ�þ�����Ҫ�޸Ĵ���Ĳ���
		for (int i = 0; i < words.size()-1;i++)
		{
			if (words[i] == words[i + 1].substr(0, words[i].size()))
			{
				continue;
			}
			ret += words[i].size() + 1;
		}
		return ret+words.back().size()+1;//���һ����ĵ��ʿ϶������һ���������ӽ�ȥ
	}
};
