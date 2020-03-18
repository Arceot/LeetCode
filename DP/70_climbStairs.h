#include <vector>
using namespace std;
//递归试一试，据说超时
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
		vector<int> dp(n + 3, 0);//想想这里为啥+3
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n;i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
	//之所以+3是为了，在n=0 1 2时不越界。
	//这样就不需要单独判断0 1 2的情况
};