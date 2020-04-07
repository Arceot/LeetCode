#include <vector>
#include <algorithm>
using namespace std;

//����ð�ݣ��ܾ���
//class Solution {
//public:
//	vector<int> sortArray(vector<int>& nums) {
//		int flag = 1;//δ����
//		while (flag)
//		{
//			flag = 0;
//			for (int i = 1; i < nums.size();i++)
//			{
//				if (nums[i]<nums[i-1])
//				{
//					int tmp = nums[i];
//					nums[i] = nums[i - 1];
//					nums[i - 1] = tmp;
//					flag = 1;
//				}
//			}
//		}
//		return nums;
//	}
//};

//ѡ������
//class Solution {
//public:
//	vector<int> sortArray(vector<int>& nums) {
//		for (int i = 0; i < nums.size()-1;i++)
//		{
//			int min_index = i;
//			for (int j = i+1; j < nums.size();j++)
//			{
//				if (nums[j]<nums[min_index])
//				{
//					min_index = j;
//				}
//			}
//			int tmp = nums[i];
//			nums[i] = nums[min_index];
//			nums[min_index] = tmp;
//		}
//		return nums;
//	}
//};


////��������
//class Solution {
//public:
//	vector<int> sortArray(vector<int>& nums) {
//		for (int i = 1; i < nums.size();++i)
//		{
//			int current = nums[i];
//			int pre_index = i - 1;
//			while (pre_index>=0 && nums[pre_index]>current)
//			{
//				nums[pre_index + 1] = nums[pre_index];
//				pre_index--;
//			}
//			nums[pre_index + 1] = current;
//		}
//		return nums;
//	}
//};

////�鲢����
//class Solution {
//public:
//	vector<int> sortArray(vector<int>& nums) {
//		int len = nums.size();
//		if (len<2)
//		{
//			return nums;
//		}
//		int mid = len / 2;
//		vector<int> left;
//		vector<int> right;
//		left.assign(nums.begin(), nums.begin() + mid);
//		right.assign(nums.begin() + mid, nums.end());
//		return merge(sortArray(left), sortArray(right));
//	}
//	vector<int> merge(vector<int> left,vector<int> right)
//	{
//		vector<int> ret;
//		int i = 0, j = 0;
//		while (i<left.size() && j<right.size())
//		{
//			if (left[i]<right[j])
//			{
//				ret.push_back(left[i]);
//				i++;
//			}
//			else
//			{
//				ret.push_back(right[j]);
//				j++;
//			}
//		}
//		while (i<left.size())
//		{
//			ret.push_back(left[i]);
//			i++;
//		}
//		while (j<right.size())
//		{
//			ret.push_back(right[j]);
//			j++;
//		}
//		return ret;
//	}
//};

//��������
//�ж������˼·�����ǰ���������������
//http://c.biancheng.net/view/1555.html

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}

	//���ѵݹ�
	void quick_sort(vector<int>& vec,int start,int end)
	{
		if (start>=end)
		{
			return;
		}
		int p = partition(vec, start, end);
		quick_sort(vec, start, p - 1);
		quick_sort(vec, p + 1, end);
	}

	//�����������ػ�׼���λ��
	int partition(vector<int>& vec, int start, int end)
	{
		int base_val = vec[start];
		int base_pos = start;
		for (int pos = start+1; pos <= end; pos++)
		{
			if (vec[pos]<base_val)
			{
				swap(vec[pos],vec[base_pos+1]);
				swap(vec[base_pos],vec[base_pos+1]);
				base_pos++;
			}
		}
		return base_pos;
	}

};