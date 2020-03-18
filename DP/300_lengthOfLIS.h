#include <vector>
#include <algorithm>
using namespace std;
//题目：最长上升子序列
//方法：DP
//关键：dp[i],以第i个数字结尾的最长上升子序列的长度
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		int maxdp = 1;
		for (int i = 0; i < nums.size();i++)
		{
			dp[i] = 1;
			for (int j = 0; j<i;j++)
			{
				if (nums[i]>nums[j])
				{
					dp[i] = max(dp[i],dp[j]+1);
				}
			}
			maxdp = max(dp[i],maxdp);
		}
		return maxdp;
	}
};