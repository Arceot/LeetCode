//LeetCode 315
#include <vector>
#include <algorithm>
using namespace std;

struct BSTNode//����Ķ��������
{
	int val;
	int count;//�������������нڵ�ĸ���
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x) :val(x),count(0), left(NULL), right(NULL) {}
};


//����������
//https://www.bilibili.com/video/av29912609/?p=6&t=8946 ��5
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<BSTNode*> nodeVec;//�����Ķ���������ڵ��
		vector<int> countVec;//�Ӻ���ǰ���������,��¼�������бȲ���ڵ�С�ĸ���
		//��nums����nodeVec��
		for (int i =0; i <nums.size(); i++)
		{
			nodeVec.push_back(new BSTNode(nums[i]));
			countVec.push_back(0);
		}
		//�Ӻ���ǰ���ڵ�һ������������������У�
		//������������������нڵ�ĸ������Ͷ������бȲ���ڵ�С�ĸ���
		for (int i = nodeVec.size()-2; i >=0; i--)
		{
			BST_insert(nodeVec[nodeVec.size() - 1], nodeVec[i], countVec[i]);
		}
		//ɾ���ڵ㣬�ͷ��ڴ�
		for (int i = nodeVec.size() - 1; i >= 0; i--)
		{
			delete nodeVec[i];
		}
		return countVec;
	}

private:
	void BST_insert(BSTNode* node, BSTNode* insert_node, int& small_count)
	{
		if (insert_node->val <= node->val)//ע����������е���ʱҲҪ���뵽��������
		{
			node->count++;//���ڵ�ǰ�ڵ������������һ���ڵ�ʱ����ǰ�ڵ��countֵ+1
			if (node->left == NULL)//������Ϊ��ʱ��ֱ�Ӳ���
			{
				node->left = insert_node;
			}
			else//��������Ϊ��ʱ���Ե�ǰ�������ڵ�Ϊ����������±���
			{
				BST_insert(node->left, insert_node, small_count);
			}
		}
		else
		{
			//��node�ڵ������������ʱ����Ҫ��node��count�ӵ�small_count��,
			//����nodeС�ڵ�ǰ��insert_node����˻���Ҫ+1
			small_count += node->count + 1;//��������+=
			if (node->right == NULL)
			{
				node->right = insert_node;
			}
			else
			{
				BST_insert(node->right, insert_node, small_count);
			}
		}
	}
};


////����
//class Solution
//{
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		vector<pair<int, int>> numPairVec;
//		vector<int> countVec(nums.size(), 0);
//		for (int i = 0; i < nums.size(); i++)
//		{
//			//��nums[i]��i��Ϊpair<nums[i],i>
//			numPairVec.push_back(make_pair(nums[i], i));
//		}
//		merge_sort(numPairVec, countVec);
//
//		return countVec;
//	}
//private:
//
//	void merge_two_sort(
//		vector<pair<int, int>>& subVec1,
//		vector<pair<int, int>>& subVec2,
//		vector<pair<int, int>>& numPairVec,
//		vector<int>& countVec)
//	{
//		int i = 0, j = 0;
//		while (i < subVec1.size() && j < subVec2.size())
//		{
//			if (subVec1[i].first <= subVec2[j].first)
//			{
//				//countVec�������Ǻ�ԭ���������һ�µģ�
//				//������numPairVec��pair��pair.second��¼��pair.first��ԭ��λ�ã�
//				//��countVec�е�����һ�¡�
//				//����subVec1ʱ�ı�count������subVec2ʱ���ı䣬
//				//������̳̽��⣺https://www.bilibili.com/video/av29912609?t=11926&p=4
//				countVec[subVec1[i].second] += j;
//				numPairVec.push_back(subVec1[i]);
//				i++;
//			}
//			//if (subVec1[i].first>subVec2[j].first)
//			else
//			{
//				numPairVec.push_back(subVec2[j]);
//				j++;
//			}
//		}
//		for (; i < subVec1.size(); i++)//subVec1��ʣ��
//		{
//			countVec[subVec1[i].second] += j;
//			numPairVec.push_back(subVec1[i]);
//		}
//		for (; j < subVec2.size(); j++)//subVec1��ʣ��
//		{
//			numPairVec.push_back(subVec2[j]);
//		}
//	}
//
//	void merge_sort(vector<pair<int, int>>& numPairVec, vector<int>& countVec)
//	{
//		if (numPairVec.size() < 2)//���������㹻Сʱֱ�����
//		{
//			return;
//		}
//		int mid = numPairVec.size() / 2;
//		vector<pair<int, int>> subVec1;
//		vector<pair<int, int>> subVec2;
//
//		//��ԭ������зֽ⣬����ԭ����ֽ�Ϊ��ģ��ͬ���������飬�ٷֱ����
//		for (int i = 0; i < mid; i++)
//		{
//			subVec1.push_back(numPairVec[i]);
//		}
//		for (int i = mid; i < numPairVec.size(); i++)
//		{
//			subVec2.push_back(numPairVec[i]);
//		}
//		merge_sort(subVec1, countVec);//�Էֽ�������������������
//		merge_sort(subVec2, countVec);
//		numPairVec.clear();
//		merge_two_sort(subVec1, subVec2, numPairVec, countVec);
//	}
//};