//https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
//抄的别人的题解，还需要自己体会体会
//贪心+dfs+剪枝
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount==0)
		{
			return 0;
		}
		sort(coins.rbegin(),coins.rend());
		int ans = INT_MAX;
		coinChange(coins, amount, 0, 0, ans);
		return ans == INT_MAX ? -1 : ans;
	}
	void coinChange(vector<int>& coins,int amount,
		int c_index,int count,int& ans)
	{
		if (amount==0)
		{
			ans = min(ans,count);
		}
		if (c_index==coins.size())
		{
			return;
		}
		for (int k = amount / coins[c_index]; 
			k >= 0 && k + count < ans;k--)//剪枝
		{
			coinChange(coins, amount - k*coins[c_index],
				c_index + 1, count + k, ans);
		}
	}
};

//dp
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1,-1);//将所有金额最优解初始化为-1，表示不可达到
		dp[0] = 0;//金额0最优解为0
		for (int i = 1; i <= amount;i++)//递推
		{
			for (int j = 0; j < coins.size();j++)//循环各个面值找到dp[i]最优解
			{
				if (coins[j]<=i&&dp[i-coins[j]]!=-1)//递推条件
				{
					if (dp[i]==-1||dp[i]>dp[i-coins[j]]+1)
					{
						dp[i] = dp[i - coins[j]] + 1;//递推公式
					}
				}
			}
		}
		return dp[amount];
	}
};