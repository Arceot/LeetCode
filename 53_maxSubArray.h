#include <vector>
#include <algorithm>
using namespace std;

//DP
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			return nums[0];
		}
		//以nums[i]结尾的最大子段和
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int flag = 1;
		int maxdp = dp[0];
		for (int i = 1; i < nums.size(); i++)
		{
			//如果dp[i-1]>=0,就把前面那一段带上，不然就不带，重新开始一段
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			//上面那一行代码也就相当于下面这一段
			/*if (dp[i - 1] >= 0)
			{
			dp[i] = dp[i - 1] + nums[i];
			}
			else
			{
			dp[i] = nums[i];
			}*/

			if (dp[i]>maxdp)
			{
				maxdp = dp[i];
			}
		}
		return maxdp;
	}
};

//想用双指针做，但是没有成功，原因在于这里面有负数，所以有点问题....
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size()==0)
		{
			return 0;
		}
		int left = 0;
		int maxsum = -INT_MAX;
		int sum = 0;
		for (int i = 0; i < nums.size();i++)
		{
			sum += nums[i];
			if (nums[i]<=0)
			{
				continue;
			}
			while (left<i && sum<=maxsum)
			{
				sum -= nums[left];
				left++;
			} 
			if (sum>maxsum)
			{
				maxsum = sum;
			}
		}
		return maxsum;
	}
};


//还有一种思路 其实是和上面一样的，当sum小于0时，就把它置为0，
//也相当于不要前面那一段了，新开一段
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int maxsum = nums[0];
		for (int i = 0; i < nums.size();i++)
		{
			sum += nums[i];
			if (sum>maxsum)
			{
				maxsum = sum;
			}
			if (sum<0)
			{
				sum = 0;
			}
		}
		return maxsum;
	}
};
