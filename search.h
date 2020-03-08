#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		if (begin<=end)//����Ϊ�գ�����-1
			return refind(nums, begin, end, target);
		return -1;
	}
private:
	int refind(vector<int>& nums,int begin,int end,int target)
	{
		int mid = (begin + end) / 2;
		if (nums[mid]==target)
			return mid;
		//������һ��Ϊ����target�����򲿷�������ֲ飬target�ڲ�����������ݹ�
		//ǰ���� �� ��ǰ
		else if (nums[begin]<=target && target<nums[mid])
			return find_target(nums, begin, mid - 1, target);

		//������ �� ����ǰ
		else if (nums[end] < nums[mid])
			return refind(nums, mid + 1, end, target);

		//������ �� �ں�
		else if (nums[mid]<target && target <= nums[end])
			return find_target(nums, mid + 1, end, target);

		//ǰ���� �� ���ں�
		else if (nums[begin]>nums[mid])
			return refind(nums, begin, mid - 1, target);

		return -1;
	}

	//���ַ���target��λ��
	int find_target(vector<int>& nums,int begin,int end,int target)
	{
		while (begin<=end)
		{
			int mid = (end + begin) / 2;
			if (target == nums[mid])
				return mid;

			else if (target > nums[mid])
			{
				if (mid == nums.size() - 1 || target < nums[mid + 1])
					return -1;
				begin = mid + 1;//ע������
			}

			else if (target<nums[mid])
			{
				if (mid == 0 || target>nums[mid - 1])
					return -1;
				end = mid - 1;//ע������
			}
		}
		return -1;
	}
};