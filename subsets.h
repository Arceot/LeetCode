#include <vector>
#include <cmath>
using namespace std;


//λ����
//class Solution
//{
//public:
//	vector<vector<int>> subsets(vector<int>& nums)
//	{
//		vector<vector<int>> resultVec;
//		int resultNum = pow(2,nums.size());
//		//int resultNum = 1 << nums.size();//�ܹ���2^num.size()���Ӽ�����λ�������1<<nums.size()
//		for (int i = 0; i < resultNum; i++)
//		{
//			vector<int> itemVec;
//			for (int j = 0; j < nums.size(); j++)
//			{
//				if (i&(1 << j))//1����jλ���ٽ��а�λ������
//				{
//					itemVec.push_back(nums[j]);
//				}
//			}
//			resultVec.push_back(itemVec);
//		}
//		return resultVec;
//	}
//};



//�ݹ� ���ݷ� ��Ƶ�еĽⷨ
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<int> itemVec;
//		vector<vector<int>> resultVec;
//		resultVec.push_back(itemVec);//���ռ�push��ȥ
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
//		itemVec.pop_back();//����
//		generate(i + 1, nums, itemVec, resultVec);
//	}
//};


//�ݹ� ���ݷ� ��̳�еĽⷨ ���ָ������
//http://wenda.chinahadoop.cn/question/6864

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> itemVec;
		vector<vector<int>> resultVec;
		//resultVec.push_back(itemVec);//���ռ�push��ȥ
		generate(0, nums, itemVec, resultVec);
		return resultVec;
	}
	void generate(int i, vector<int>& nums, vector<int> itemVec, vector<vector<int>>& resultVec)
	{
		if (i >= nums.size())
		{
			resultVec.push_back(itemVec);//����һ���ݹ�·�ߵĽ��
			return;
		}
		itemVec.push_back(nums[i]);//����
		generate(i + 1, nums, itemVec, resultVec);
		itemVec.pop_back();//����
		generate(i + 1, nums, itemVec, resultVec);
	}
};