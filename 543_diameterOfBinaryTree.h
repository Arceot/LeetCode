//深度遍历。难点最大直径不一定经过root，
//需遍历每一个节点，以之为根，计算其最大直径
//并与之前计算的直径最大值进行比较
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int max_len = 0;
		DFS(root,max_len);
		return max_len;
	}

	//返回以node为根，的树的最大深度
	int DFS(TreeNode* node, int& max_len)
	{
		if (node==NULL)
		{
			return 0;
		}
		//计算其左子树的深度
		int left_len=DFS(node->left,max_len);
		//计算其右子树的深度
		int right_len=DFS(node->right,max_len);
		//max_len记录以node为根，
		//其左子树的深度与右子树的深度之和
		if (left_len+right_len>max_len)
		{
			max_len = left_len + right_len;
		}
		//返回以node为根，的树的最大深度
		return max(left_len,right_len)+1;
	}
};