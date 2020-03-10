//��ȱ������ѵ����ֱ����һ������root��
//�����ÿһ���ڵ㣬��֮Ϊ�������������ֱ��
//����֮ǰ�����ֱ�����ֵ���бȽ�
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

	//������nodeΪ����������������
	int DFS(TreeNode* node, int& max_len)
	{
		if (node==NULL)
		{
			return 0;
		}
		//�����������������
		int left_len=DFS(node->left,max_len);
		//�����������������
		int right_len=DFS(node->right,max_len);
		//max_len��¼��nodeΪ����
		//��������������������������֮��
		if (left_len+right_len>max_len)
		{
			max_len = left_len + right_len;
		}
		//������nodeΪ����������������
		return max(left_len,right_len)+1;
	}
};