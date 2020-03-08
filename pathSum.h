#include <vector>
using namespace std;//头文件中一般不允许使用using namespace；此处为了方便就用了
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> itemVec;
		int itemSum = 0;
		generate(root, sum, itemSum, itemVec, result);
		return result;

	}
private:
	void generate(TreeNode* root, int sum, int& itemSum,
		vector<int>& itemVec, vector<vector<int>>& result)
	{
		if (root == NULL)
		{
			return;
		}
		//前序的工作
		itemSum += root->val;
		itemVec.push_back(root->val);
		if (root->left == NULL && root->right == NULL && itemSum == sum)
		{
			result.push_back(itemVec);
		}
		generate(root->left, sum, itemSum, itemVec, result);
		generate(root->right, sum, itemSum, itemVec, result);
		//后序的工作
		itemVec.pop_back();
		itemSum -= root->val;
	}
};