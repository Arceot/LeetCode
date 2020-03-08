#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int curMaxIndex = 0;
		int preCurMaxIndex = 0;
		int jumpSteps = 0;
		for (int i = 0; i < nums.size();i++)
		{
			if (i>curMaxIndex)
			{
				curMaxIndex = preCurMaxIndex;
				jumpSteps++;
			}
			if (nums[i]+i>preCurMaxIndex)
			{
				preCurMaxIndex = nums[i] + i;
			}
		}
		return jumpSteps;
	}
};