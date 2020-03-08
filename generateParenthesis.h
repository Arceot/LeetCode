#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> reVec;
		generate("",n,0,0,reVec);
		return reVec;
	}
private:
	void generate(string item,int n,int left,int right,vector<string>& reVec)
	{
		if (left==n && right==n)//�������������ŵ�������Ϊnʱ�˳��ݹ�
		{
			reVec.push_back(item);
			return;
		}
		if (left<n)//�������ŵ�����С��nʱ���ſ��Է�������
		{
			generate(item + '(', n,left+1,right,reVec);
		}
		if (left>right)//�������ŵ��������������ŵ�����ʱ���ſ��Է���������
		{
			generate(item + ')', n, left, right+1, reVec);
		}
	}
};