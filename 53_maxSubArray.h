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
		//��nums[i]��β������Ӷκ�
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int flag = 1;
		int maxdp = dp[0];
		for (int i = 1; i < nums.size(); i++)
		{
			//���dp[i-1]>=0,�Ͱ�ǰ����һ�δ��ϣ���Ȼ�Ͳ��������¿�ʼһ��
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			//������һ�д���Ҳ���൱��������һ��
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

//����˫ָ����������û�гɹ���ԭ�������������и����������е�����....
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


//����һ��˼· ��ʵ�Ǻ�����һ���ģ���sumС��0ʱ���Ͱ�����Ϊ0��
//Ҳ�൱�ڲ�Ҫǰ����һ���ˣ��¿�һ��
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
