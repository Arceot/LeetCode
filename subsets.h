#include <vector>
#include <cmath>
using namespace std;


//位运算
//class Solution
//{
//public:
//	vector<vector<int>> subsets(vector<int>& nums)
//	{
//		vector<vector<int>> resultVec;
//		int resultNum = pow(2,nums.size());
//		//int resultNum = 1 << nums.size();//总共有2^num.size()个子集，用位运算就是1<<nums.size()
//		for (int i = 0; i < resultNum; i++)
//		{
//			vector<int> itemVec;
//			for (int j = 0; j < nums.size(); j++)
//			{
//				if (i&(1 << j))//1左移j位，再进行按位与运算
//				{
//					itemVec.push_back(nums[j]);
//				}
//			}
//			resultVec.push_back(itemVec);
//		}
//		return resultVec;
//	}
//};



//递归 回溯法 视频中的解法
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<int> itemVec;
//		vector<vector<int>> resultVec;
//		resultVec.push_back(itemVec);//将空集push进去
//		generate(0, nums, itemVec, resultVec);
//		return resultVec;
//	}
//
//	void generate(int i, vector<int>& nums, vector<int> itemVec,vector<vector<int>>& resultVec)
//	{
//		if (i >= nums.size())
//			return;
//		itemVec.push_back(nums[i]);
//		resultVec.push_back(itemVec);
//
//		generate(i + 1, nums, itemVec, resultVec);
//
//		itemVec.pop_back();//回溯
//		generate(i + 1, nums, itemVec, resultVec);
//	}
//};


//递归 回溯法 论坛中的解法 这种更好理解
//http://wenda.chinahadoop.cn/question/6864

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> itemVec;
		vector<vector<int>> resultVec;
		//resultVec.push_back(itemVec);//将空集push进去
		generate(0, nums, itemVec, resultVec);
		return resultVec;
	}
	void generate(int i, vector<int>& nums, vector<int> itemVec, vector<vector<int>>& resultVec)
	{
		if (i >= nums.size())
		{
			resultVec.push_back(itemVec);//保存一条递归路线的结果
			return;
		}
		itemVec.push_back(nums[i]);//放入
		generate(i + 1, nums, itemVec, resultVec);
		itemVec.pop_back();//不放
		generate(i + 1, nums, itemVec, resultVec);
	}
};