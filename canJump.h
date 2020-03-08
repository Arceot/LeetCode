#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> numsJump;
		for (int i = 0; i < nums.size();i++)
		{
			numsJump.push_back(i+nums[i]);//当前位置可跳到的绝对位置
		}
		int jump = 0;
		int maxIndex = numsJump[0];
		while (jump<nums.size() && jump<=maxIndex)
		{
			if (maxIndex<numsJump[jump])
			{
				maxIndex = numsJump[jump];
			}
			jump++;
		}
		if (jump==nums.size())
		{
			return true;
		}
		return false;
	}
};