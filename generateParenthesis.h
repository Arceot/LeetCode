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
		if (left==n && right==n)//左括号与有括号的数量都为n时退出递归
		{
			reVec.push_back(item);
			return;
		}
		if (left<n)//当左括号的数量小于n时，才可以放左括号
		{
			generate(item + '(', n,left+1,right,reVec);
		}
		if (left>right)//当左括号的数量大于右括号的数量时，才可以放置右括号
		{
			generate(item + ')', n, left, right+1, reVec);
		}
	}
};