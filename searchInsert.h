#include <vector>
using namespace std;

//LeetCode 35 ����
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int index = -1, begin = 0, end = nums.size() - 1;
		while (index == -1)
		{
			int mid = (end + begin) / 2;
			if (target == nums[mid])
				return mid;
			if (target > nums[mid])
			{
				if (mid == nums.size() - 1 || target < nums[mid + 1])
				{
					return mid + 1;
				}
				begin = mid + 1;//ע������
			}
			if (target<nums[mid])
			{
				if (mid == 0 || target>nums[mid - 1])
				{
					return mid;
				}
				end = mid - 1;//ע������
			}
		}
		return index;
	}
};