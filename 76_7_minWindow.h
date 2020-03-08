#include <string>
#include <map>
#include <vector>
using namespace std;
//https://leetcode-cn.com/problems/minimum-window-substring/solution/zhe-dao-ti-de-nan-dian-fen-xi-by-wang-yan-19/
//https://leetcode-cn.com/problems/minimum-window-substring/solution/c-unordered_map-8ms-9847-by-karlzhang/
//����˼·�ο����������
//����ģ���������¸����ķ������н����
//ע��t�п������ظ����ַ�
//˫ָ�룬left��i������


class Solution {
public:
	string minWindow(string s, string t) {
		int t_char_map[128] = { 0 };
		int left = 0, start = left;
		//��minlen��һ�������в����ܴﵽ��ֵ����������һ�����
		int minlen = s.size() + 1;
		//count�����жϵ�ǰ�����Ƿ�����Ҫ��
		int count = 0;
		for (int i = 0; i < t.size(); i++)
		{
			//��ʼ��map
			t_char_map[t[i]]++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			t_char_map[s[i]]--;
			//˵��s��ǰ��char������t�е�ĳ��char
			if (t_char_map[s[i]] >= 0)
			{
				count++;
			}

			//��count == t.size()ʱ˵�������ˣ�
			//��ǰ���ڷ���Ҫ��
			while (count == t.size())//������
			{
				//�洢���ȴ��ڵ���ʼλ�úͳ��ȣ�
				//��Ϊsubstr��Ҫ������Ԫ��
				if (i - left + 1 <= minlen)
				{
					minlen = i - left + 1;
					start = left;
				}
				//׼���ƶ�left
				t_char_map[s[left]]++;
				//��ʱt_char_map[s[left]]ҪôΪ0��ҪôΪ��
				/*
				��ʱ���������
				1.s[left]���ڲ���t��
				2.s[left]��t�У����Ǵ�����s[left]����������t��s[left]������
				*/
				//��(t_char_map[s[left]] > 0ʱ��˵���Ȼ����ȥ������t�е��ַ�
				//�Ҵ�ʱ������s[left]��������t��s[left]��������ȣ�
				//��˵��ȥ��s[left]����������Ѿ�������������
				if (t_char_map[s[left]] > 0)
				{
					count--;
				}
				left++;
			}
		}
		return minlen == s.size() + 1 ? "" : s.substr(start, minlen);
	}
};


////��Ƶ�еķ�����˼·���ԣ�����̫��ʱ���ˡ���covered�����ʱ
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string ret = "";
//		int begin = 0;
//		const int MAX_LEN = 128;
//		int s_char_map[MAX_LEN] = { 0 };//��¼s��begin��i֮���ַ����ֵĴ���
//		int t_char_map[MAX_LEN] = { 0 };//��¼t���ַ����ֵĴ���
//		for (int i = 0; i < t.length(); i++)
//			t_char_map[t[i]]++;
//
//		for (int i = 0; i < s.length(); i++)
//		{
//			s_char_map[s[i]]++;
//
//			//��beginС��i�������ƶ�begin
//			while (begin<i)
//			{
//				if (t.find(s[begin]) == -1)//s[begin]����t��
//				{
//					s_char_map[s[begin]]--;
//					begin++;
//				}
//				//s[begin]��t�У��ҵ�ǰ�Ӵ���s[begin]��������t��s[begin]����Ŀ��
//				else if (s_char_map[s[begin]]>t_char_map[s[begin]])
//				{
//					s_char_map[s[begin]]--;
//					begin++;
//				}
//				else
//					break;
//			}
//
//			//�ж�t�е��ַ��Ƿ���word�г��ֹ�,���������
//			if (s_char_map[s[begin]]==t_char_map[s[begin]]
//				&&covered(s_char_map, t_char_map, t))
//			{
//				if (ret == "" || (i - begin + 1) < ret.length())
//				{
//					ret = s.substr(begin, i - begin + 1);
//				}
//				//���������仰�û��ᳬʱ����ʹ�����ˣ�ʱ��Ҳ��ܳ����������ַ�����˼·���ԡ�����̫��ʱ�ˡ�
//				s_char_map[s[begin]]--;//ע����s[begin],����д����begin
//				begin++;
//			}
//		}
//		return ret;
//	}
//private:
//	bool covered(int s_char_map[], int t_char_map[], string t)
//	{
//		for (int i = 0; i < t.length(); i++)
//		{
//			if (s_char_map[t[i]] < t_char_map[t[i]])//ע��������С��
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};