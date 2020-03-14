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
		//��ÿһ���������η���ÿ��Ͱ�г���
		for (int j = 0; j < 4;j++)
		{
			//�����һ��Ͱ�Ų���ȥ�ͷŵڶ���Ͱ......
			if (bucket[j]+nums[i]>target)
			{
				continue;
			}
			bucket[j] += nums[i];
			//�������
			if(DFS(i + 1, nums, target, bucket))
				return true;
			//����,�ѵ�i�����˴ӵ�j��Ͱ�ó�����
			//���Է����j+1��Ͱ
			bucket[j] -= nums[i];
		}
		return false;
	}
};