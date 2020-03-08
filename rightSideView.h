#include <vector>
#include <queue>
using namespace std;//头文件中一般不允许使用using namespace；此处为了方便就用了

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

			if (reVec.size() == deepth)//这里的if else 需要好好体会一下
			{
				reVec.push_back(node->val);
			}
			else//后面同一层的直接覆盖reVec[deepth]
			{
				reVec[deepth] = node->val;
			}
			if (node->left != NULL)//按层从左到右遍历
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