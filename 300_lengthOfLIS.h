#include <vector>
#include <algorithm>
using namespace std;
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