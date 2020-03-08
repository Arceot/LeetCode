#include<vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());//��С��������
		vector<int> itemVec;
		vector<vector<int>> retVec;
		set<vector<int>> retSet;//ȥ��ʹ�õļ���
		int sum=0;
		generate(0, candidates, itemVec, retVec, retSet, target,sum);
		return retVec;
	}
private:
	void generate(int i, vector<int>& nums, vector<int>& itemVec,
		vector<vector<int>>& retVec, set<vector<int>>& retSet, int& target,int& sum)//ע�⴫�ݵ�������
	{
		if (i >= nums.size())
		{
			return;
		}
		sum = sum + nums[i];
		if (sum>target)//������������ʱ����ǰ��֦
		{
			sum = sum - nums[i];
			return;
		}
		itemVec.push_back(nums[i]);
		if (sum==target && retSet.find(itemVec) == retSet.end())//���ظ�ʱ�ż���
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