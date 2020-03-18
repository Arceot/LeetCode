#include <vector>
using namespace std;
//�ݹ���һ�ԣ���˵��ʱ
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2)
		{
			return n;
		}
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
};

//DP
class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n + 3, 0);//��������Ϊɶ+3
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n;i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
	//֮����+3��Ϊ�ˣ���n=0 1 2ʱ��Խ�硣
	//�����Ͳ���Ҫ�����ж�0 1 2�����
};