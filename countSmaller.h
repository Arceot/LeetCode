//LeetCode 315
#include <vector>
#include <algorithm>
using namespace std;

struct BSTNode//改造的二叉查找树
{
	int val;
	int count;//二叉树左子树中节点的个数
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x) :val(x),count(0), left(NULL), right(NULL) {}
};


//二叉排序树
//https://www.bilibili.com/video/av29912609/?p=6&t=8946 例5
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<BSTNode*> nodeVec;//创建的二叉查找树节点池
		vector<int> countVec;//从后向前插入过程中,记录二叉树中比插入节点小的个数
		//将nums插入nodeVec中
		for (int i =0; i <nums.size(); i++)
		{
			nodeVec.push_back(new BSTNode(nums[i]));
			countVec.push_back(0);
		}
		//从后向前将节点一个个插入二叉排序树中，
		//并计算二叉树左子树中节点的个数，和二叉树中比插入节点小的个数
		for (int i = nodeVec.size()-2; i >=0; i--)
		{
			BST_insert(nodeVec[nodeVec.size() - 1], nodeVec[i], countVec[i]);
		}
		//删除节点，释放内存
		for (int i = nodeVec.size() - 1; i >= 0; i--)
		{
			delete nodeVec[i];
		}
		return countVec;
	}

private:
	void BST_insert(BSTNode* node, BSTNode* insert_node, int& small_count)
	{
		if (insert_node->val <= node->val)//注意在这个题中等于时也要插入到左子树中
		{
			node->count++;//当在当前节点的左子树插入一个节点时，当前节点的count值+1
			if (node->left == NULL)//左子树为空时，直接插入
			{
				node->left = insert_node;
			}
			else//左子树不为空时，以当前左子树节点为顶点继续向下遍历
			{
				BST_insert(node->left, insert_node, small_count);
			}
		}
		else
		{
			//当node节点的右子树插入时，需要将node的count加到small_count中,
			//并且node小于当前的insert_node，因此还需要+1
			small_count += node->count + 1;//体会这里的+=
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


////分治
//class Solution
//{
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		vector<pair<int, int>> numPairVec;
//		vector<int> countVec(nums.size(), 0);
//		for (int i = 0; i < nums.size(); i++)
//		{
//			//将nums[i]与i绑定为pair<nums[i],i>
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
//				//countVec的排序是和原数组的排序一致的，
//				//排序后的numPairVec中pair的pair.second记录了pair.first的原来位置，
//				//和countVec中的索引一致。
//				//插入subVec1时改变count，插入subVec2时不改变，
//				//具体见教程讲解：https://www.bilibili.com/video/av29912609?t=11926&p=4
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
//		for (; i < subVec1.size(); i++)//subVec1有剩余
//		{
//			countVec[subVec1[i].second] += j;
//			numPairVec.push_back(subVec1[i]);
//		}
//		for (; j < subVec2.size(); j++)//subVec1有剩余
//		{
//			numPairVec.push_back(subVec2[j]);
//		}
//	}
//
//	void merge_sort(vector<pair<int, int>>& numPairVec, vector<int>& countVec)
//	{
//		if (numPairVec.size() < 2)//当子问题足够小时直接求解
//		{
//			return;
//		}
//		int mid = numPairVec.size() / 2;
//		vector<pair<int, int>> subVec1;
//		vector<pair<int, int>> subVec2;
//
//		//对原问题进行分解，即将原数组分解为规模相同的两个数组，再分别求解
//		for (int i = 0; i < mid; i++)
//		{
//			subVec1.push_back(numPairVec[i]);
//		}
//		for (int i = mid; i < numPairVec.size(); i++)
//		{
//			subVec2.push_back(numPairVec[i]);
//		}
//		merge_sort(subVec1, countVec);//对分解后的两个子问题进行求解
//		merge_sort(subVec2, countVec);
//		numPairVec.clear();
//		merge_two_sort(subVec1, subVec2, numPairVec, countVec);
//	}
//};