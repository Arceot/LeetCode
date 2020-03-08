#include <vector>
#include <set>
using namespace std;//头文件中一般不允许使用using namespace；此处为了方便就用了

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pathVec;
		vector<TreeNode*> pResultVec;
		vector<TreeNode*> qResultVec;
		TreeNode* result=0;
		int isFinish = 0;
		findPathVec(root, p, pathVec, pResultVec, isFinish);

		pathVec.clear();
		isFinish = 0;
		findPathVec(root, q, pathVec, qResultVec, isFinish);

		int pathLength=0;
		if (qResultVec.size()<pResultVec.size())
		{
			pathLength = qResultVec.size();
		}
		else
		{
			pathLength = pResultVec.size();
		}
		for (int i =0; i <pathLength; i++)
		{
			if (pResultVec[i]==qResultVec[i])
			{
				result = pResultVec[i];
			}
		}
		return result;
	}
private:
	void findPathVec(TreeNode* root, TreeNode* p,
		vector<TreeNode*>& pathVec,
		vector<TreeNode*>& resultVec, int& isFinish)
	{
		if (root == NULL || isFinish == 1)
		{
			return;
		}
		pathVec.push_back(root);
		if (root == p)
		{
			isFinish = 1;
			resultVec = pathVec;
		}
		findPathVec(root->left, p, pathVec, resultVec, isFinish);
		findPathVec(root->right, p, pathVec, resultVec, isFinish);
		pathVec.pop_back();
	}
};