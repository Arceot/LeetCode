#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size()<4)
		{
			return false;
		}
		int sum = 0;
		for (int i = 0; i < nums.size();i++)
		{
			sum += nums[i];
		}
		if (sum%4!=0)
		{
			return false;
		}
		sort(nums.rbegin(), nums.rend());
		int bucket[4] = {0};
		return DFS(0,nums,sum/4,bucket);
	}
	
	bool DFS(int i,vector<int>& nums,int target,int bucket[])
	{
		if (i==nums.size())
		{
			return bucket[0] == target&&bucket[1] == target
				&&bucket[2] == target&&bucket[3] == target;
		}
		//将每一个火柴杆依次放入每个桶中尝试
		for (int j = 0; j < 4;j++)
		{
			//如果第一个桶放不进去就放第二个桶......
			if (bucket[j]+nums[i]>target)
			{
				continue;
			}
			bucket[j] += nums[i];
			//深度搜索
			if(DFS(i + 1, nums, target, bucket))
				return true;
			//回溯,把第i个火柴杆从第j个桶拿出来，
			//尝试放入第j+1个桶
			bucket[j] -= nums[i];
		}
		return false;
	}
};