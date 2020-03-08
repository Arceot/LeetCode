#include<vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());//从小到大排序
		vector<int> itemVec;
		vector<vector<int>> retVec;
		set<vector<int>> retSet;//去重使用的集合
		int sum=0;
		generate(0, candidates, itemVec, retVec, retSet, target,sum);
		return retVec;
	}
private:
	void generate(int i, vector<int>& nums, vector<int>& itemVec,
		vector<vector<int>>& retVec, set<vector<int>>& retSet, int& target,int& sum)//注意传递的是引用
	{
		if (i >= nums.size())
		{
			return;
		}
		sum = sum + nums[i];
		if (sum>target)//当不符合条件时，提前剪枝
		{
			sum = sum - nums[i];
			return;
		}
		itemVec.push_back(nums[i]);
		if (sum==target && retSet.find(itemVec) == retSet.end())//不重复时才加入
		{
			retVec.push_back(itemVec);
			retSet.insert(itemVec);
		}
		generate(i + 1, nums, itemVec, retVec, retSet,target,sum);
		itemVec.pop_back();
		sum = sum - nums[i];
		generate(i + 1, nums, itemVec, retVec, retSet, target, sum);
	}
};