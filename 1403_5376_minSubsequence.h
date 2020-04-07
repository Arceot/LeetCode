#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	static bool cmp(int& a,int& b)
	{
		return a > b;
	}
	vector<int> minSubsequence(vector<int>& nums) {
		vector<int> ret_vec;
		sort(nums.begin(),nums.end(),cmp);
		int sum = 0;
		for (int i = 0; i < nums.size();++i)
		{
			sum += nums[i];
		}
		int sub_sum = 0;
		for (int i = 0; i < nums.size();i++)
		{
			ret_vec.push_back(nums[i]);
			sub_sum += nums[i];
			sum -= nums[i];
			if (sub_sum>sum)
			{
				break;
			}
		}
		return ret_vec;
	}
};