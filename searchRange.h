#include <vector>
using namespace std;

//LeetCode 34 ������  ���ַ� ʱ�临�Ӷ�ΪO(log n) �������е�Ҫ��
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		//if (nums.size()==0)//begin<end �ų���numsΪ�յ����
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
		while (begin<=end)//begin<end �ų���numsΪ�յ����
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


//LeetCode 34 ������  ʱ�临�Ӷ�ΪO(n) ���������е�Ҫ��
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int index = -1, begin = 0, end = nums.size() - 1;
//		vector<int> reVec;
//		reVec.push_back(-1);
//		reVec.push_back(-1);
//		if (end==-1)//�ж�nums�Ƿ�Ϊ��
//			return reVec;
//		//���ҵ�1������0��target��λ��
//		while (index == -1)
//		{
//			int mid = (end + begin) / 2;
//			if (target == nums[mid])
//				index=mid;
//			if (target > nums[mid])
//			{
//				//��������Ҷ˵㻹�� ���� û�ҵ�
//				if (mid == nums.size() - 1 || target < nums[mid + 1])
//				{
//					return reVec;
//				}
//				begin = mid + 1;//ע������
//			}
//			if (target<nums[mid])
//			{
//				//���������˵㻹С ���� û�ҵ�
//				if (mid == 0 || target>nums[mid - 1])
//				{
//					return reVec;
//				}
//				end = mid - 1;//ע������
//			}
//		}
//		reVec.clear();
//		int temp = index;
//
//		//ʱ�临�Ӷȸ�
//		//����˵�
//		while (nums[index]==target)
//		{
//			index--;
//			if (index<0)
//				break;
//		}
//		reVec.push_back(index+1);
//		index = temp;
//		//���Ҷ˵�
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