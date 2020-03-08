#include <vector>
using namespace std;//ͷ�ļ���һ�㲻����ʹ��using namespace���˴�Ϊ�˷��������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ԭ�ط�
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
		/*ǰ�� ����nodeʱ��������*/
		TreeNode* left=node->left;
		TreeNode* right = node->right;
		TreeNode* left_last=NULL;
		TreeNode* right_last = NULL;

		if (left != NULL)
		{
			preorder(left, left_last);//�ݹ���ɺ������Ϊ�������Ѿ�����ֱ��
			/*���� ����������ֱ֮�� ����node���ӵķ���*/
			node->left = NULL;
			node->right = left;
			last = left_last;
		}


		if (right!=NULL)
		{
			preorder(right, right_last);//�ݹ���ɺ������Ϊ�������Ѿ�����ֱ��
			/*���� ����������ֱ֮��*/
			if (left_last != NULL)
			{
				left_last->right = right;
			}
			last = right_last;
		}
	}
};


////��ԭ�ط�����ǰ�������vector��ٽ�vector�еĽڵ���������
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

