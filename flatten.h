#include <vector>
using namespace std;//头文件中一般不允许使用using namespace；此处为了方便就用了

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//原地法
class Solution {
public:
	void flatten(TreeNode* root)
	{
		TreeNode* last_node;
		preorder(root, last_node);
	}

private:
	void preorder(TreeNode* node, TreeNode*& last)
	{
		if (node == NULL)
			return;
		if (node->left==NULL&&node->right==NULL)
		{
			last = node;
			return;
		}
		/*前序 访问node时做的事情*/
		TreeNode* left=node->left;
		TreeNode* right = node->right;
		TreeNode* left_last=NULL;
		TreeNode* right_last = NULL;

		if (left != NULL)
		{
			preorder(left, left_last);//递归完成后，则可认为左子树已经被拉直了
			/*中序 左子树被拉直之后 进行node左孩子的访问*/
			node->left = NULL;
			node->right = left;
			last = left_last;
		}


		if (right!=NULL)
		{
			preorder(right, right_last);//递归完成后，则可认为右子树已经被拉直了
			/*后序 右子树被拉直之后*/
			if (left_last != NULL)
			{
				left_last->right = right;
			}
			last = right_last;
		}
	}
};


////非原地法：先前序遍历到vector里，再将vector中的节点连接起来
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		vector<TreeNode*> node_vec;
//		preorder(root,node_vec);
//		for (int i = 1; i < node_vec.size();i++)
//		{
//			node_vec[i - 1]->left = NULL;
//			node_vec[i - 1]->right =node_vec[i];
//		}
//	}
//private:
//	void preorder(TreeNode* root,vector<TreeNode*>& node_vec)
//	{
//		if (root==NULL)
//		{
//			return;
//		}
//		node_vec.push_back(root);
//		preorder(root->left, node_vec);
//		preorder(root->right, node_vec);
//	}
//};

