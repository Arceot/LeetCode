#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());//��С��������
		vector<int> itemVec;
		vector<vector<int>> retVec;
		retVec.push_back(itemVec);
		set<vector<int>> retSet;//ȥ��ʹ�õļ���
		generate(0, nums, itemVec, retVec, retSet);
		return retVec;
	}

private:
	void generate(int i, vector<int>& nums, vector<int>& itemVec, 
		vector<vector<int>>& retVec, set<vector<int>>& retSet)//ע�⴫�ݵ�������
	{
		if (i >= nums.size())
		{
			return;
		}
		itemVec.push_back(nums[i]);
		if (retSet.find(itemVec)==retSet.end())//���ظ�ʱ�ż���
		{
			retVec.push_back(itemVec);
			retSet.insert(itemVec);
		}
		generate(i + 1, nums, itemVec, retVec, retSet);
		itemVec.pop_back();
		generate(i + 1, nums, itemVec, retVec, retSet);
	}
};