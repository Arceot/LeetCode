#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* balanceBST(TreeNode* root) {
		vector<TreeNode*> vec;
		queue<TreeNode*> Q;
		Q.push(root);
		vec.push_back(root);
		while (!Q.empty())
		{
			TreeNode* node = Q.front();
			Q.pop();
			if (node->left)
			{
				vec.push_back(node->left);
				Q.push(node->left);
			}
			if (node->right)
			{
				vec.push_back(node->right);
				Q.push(node->right);
			}
		}
		sort(vec.begin(),vec.end(),cmp);
		TreeNode* nroot = vec[(vec.size()+1) / 2];
		nroot->left = NULL;
		nroot->right = NULL;
		for (int i = 0; i < vec.size();i++)
		{
			if (vec[i]==nroot)
			{
				continue;
			}
			vec[i]->left = NULL;
			vec[i]->right = NULL;
			make_tree(nroot, vec[i]);
		}
		return nroot;
	}

	static bool cmp(const TreeNode* a, const TreeNode* b)
	{
		return a->val < b->val;
	}

	void make_tree(TreeNode* node, TreeNode* son)
	{
		if (son->val < node->val)
		{
			if (node->left)
			{
				make_tree(node->left, son);
			}
			else
			{
				node->left = son;
			}
		}
		else
		{
			if (node->right)
			{
				make_tree(node->right, son);
			}
			else
			{
				node->right = son;
			}
		}
	}
};