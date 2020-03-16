//https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
//���ı��˵���⣬����Ҫ�Լ�������
//̰��+dfs+��֦
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
			k >= 0 && k + count < ans;k--)//��֦
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
		vector<int> dp(amount+1,-1);//�����н�����Ž��ʼ��Ϊ-1����ʾ���ɴﵽ
		dp[0] = 0;//���0���Ž�Ϊ0
		for (int i = 1; i <= amount;i++)//����
		{
			for (int j = 0; j < coins.size();j++)//ѭ��������ֵ�ҵ�dp[i]���Ž�
			{
				if (coins[j]<=i&&dp[i-coins[j]]!=-1)//��������
				{
					if (dp[i]==-1||dp[i]>dp[i-coins[j]]+1)
					{
						dp[i] = dp[i - coins[j]] + 1;//���ƹ�ʽ
					}
				}
			}
		}
		return dp[amount];
	}
};