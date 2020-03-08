#include <vector>
using namespace std;

//LeetCode 34 找区间  二分法 时间复杂度为O(log n) 符合题中的要求
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		//if (nums.size()==0)//begin<end 排除了nums为空的情况
		//{
		//	result.push_back(-1);
		//	result.push_back(-1);
		//	return result;
		//}
		result.push_back(find_left(nums, target));
		result.push_back(find_right(nums, target));
		return result;
	}

private:
	int find_left(vector<int>& nums, int target)
	{
		int begin = 0, end = nums.size() - 1;
		while (begin<=end)//begin<end 排除了nums为空的情况
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid == 0 || nums[mid - 1] < target)
				{
					return mid;
				}
				end = mid - 1;
			}
			if (nums[mid]<target)
			{
				if (mid==(nums.size()-1) || target<nums[mid+1])
				{
					return -1;
				}
				begin = mid+1;
			}
			if (nums[mid]>target)
			{
				if (mid==0 || target>nums[mid-1])
				{
					return -1;
				}
				end = mid-1;
			}
		}
		return -1;
	}

	int find_right(vector<int>& nums, int target)
	{
		int begin = 0, end = nums.size() - 1;
		while (begin<=end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid == nums.size() - 1 || nums[mid + 1] > target)
				{
					return mid;
				}
				begin = mid + 1;
			}
			if (nums[mid]<target)
			{
				if (mid==(nums.size()-1) || target<nums[mid+1])
				{
					return -1;
				}
				begin = mid+1;
			}
			if (nums[mid]>target)
			{
				if (mid==0 || target>nums[mid-1])
				{
					return -1;
				}
				end = mid-1;
			}
		}
		return -1;
	}
};


//LeetCode 34 找区间  时间复杂度为O(n) 不符合题中的要求
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int index = -1, begin = 0, end = nums.size() - 1;
//		vector<int> reVec;
//		reVec.push_back(-1);
//		reVec.push_back(-1);
//		if (end==-1)//判断nums是否为空
//			return reVec;
//		//先找到1个或者0个target的位置
//		while (index == -1)
//		{
//			int mid = (end + begin) / 2;
//			if (target == nums[mid])
//				index=mid;
//			if (target > nums[mid])
//			{
//				//比数组的右端点还大 或者 没找到
//				if (mid == nums.size() - 1 || target < nums[mid + 1])
//				{
//					return reVec;
//				}
//				begin = mid + 1;//注意这里
//			}
//			if (target<nums[mid])
//			{
//				//比数组的左端点还小 或者 没找到
//				if (mid == 0 || target>nums[mid - 1])
//				{
//					return reVec;
//				}
//				end = mid - 1;//注意这里
//			}
//		}
//		reVec.clear();
//		int temp = index;
//
//		//时间复杂度高
//		//找左端点
//		while (nums[index]==target)
//		{
//			index--;
//			if (index<0)
//				break;
//		}
//		reVec.push_back(index+1);
//		index = temp;
//		//找右端点
//		while (nums[index] == target)
//		{
//			index++;
//			if (index>nums.size()-1)
//				break;
//		}
//		reVec.push_back(index-1);
//		return reVec;
//	}
//};