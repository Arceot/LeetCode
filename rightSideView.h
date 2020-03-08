#include <vector>
#include <queue>
using namespace std;//ͷ�ļ���һ�㲻����ʹ��using namespace���˴�Ϊ�˷��������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<pair<TreeNode*,int>> Q;
		vector<int> reVec;
		if (root!=NULL)
		{
			Q.push(make_pair(root, 0));
		}

		while (!Q.empty())
		{
			TreeNode* node = Q.front().first;
			int deepth = Q.front().second;

			if (reVec.size() == deepth)//�����if else ��Ҫ�ú����һ��
			{
				reVec.push_back(node->val);
			}
			else//����ͬһ���ֱ�Ӹ���reVec[deepth]
			{
				reVec[deepth] = node->val;
			}
			if (node->left != NULL)//��������ұ���
			{
				Q.push(make_pair(node->left, deepth + 1));
			}
			if (node->right != NULL)
			{
				Q.push(make_pair(node->right, deepth + 1));
			}
			Q.pop();
		}
		return reVec;

	}
};