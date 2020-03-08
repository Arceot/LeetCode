#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());//从小到大排序
		vector<int> itemVec;
		vector<vector<int>> retVec;
		retVec.push_back(itemVec);
		set<vector<int>> retSet;//去重使用的集合
		generate(0, nums, itemVec, retVec, retSet);
		return retVec;
	}

private:
	void generate(int i, vector<int>& nums, vector<int>& itemVec, 
		vector<vector<int>>& retVec, set<vector<int>>& retSet)//注意传递的是引用
	{
		if (i >= nums.size())
		{
			return;
		}
		itemVec.push_back(nums[i]);
		if (retSet.find(itemVec)==retSet.end())//不重复时才加入
		{
			retVec.push_back(itemVec);
			retSet.insert(itemVec);
		}
		generate(i + 1, nums, itemVec, retVec, retSet);
		itemVec.pop_back();
		generate(i + 1, nums, itemVec, retVec, retSet);
	}
};