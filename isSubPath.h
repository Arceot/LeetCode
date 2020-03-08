#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (root==NULL)
		{
			return false;
		}
		if (root->val==head->val)
		{
			if (findNode(head->next,root->left)||
				findNode(head->next,root->right))
			{
				return true;
			}
		}
		else
		{
			if (findNode(head,root->left)||
				findNode(head,root->right))
			{
				return true;
			}
		}
		return false;
	}
private:
	bool findNode(ListNode* head, TreeNode* node)
	{
		if (head == NULL)//找到了路径
		{
			return true;
		}
		if (node == NULL || head->val!=node->val)//没找到，但是树空了
		{
			return false;
		}
		if (findNode(head->next,node->left)||
			findNode(head->next,node->right))
		{
			return true;
		}
		return false;
	}
};

//class Solution {
//public:
//	bool isSubPath(ListNode* head, TreeNode* root) {
//		bool finded = false;
//		findNode(head, root, finded);
//		return finded;
//	}
//private:
//	void findNode(ListNode* head,TreeNode* node,bool& finded)
//	{
//		if (head->val==node->val && head->next == NULL)//找到了路径
//		{
//			finded = true;
//			return;
//		}
//
//		if (head->val != node->val)//不相同
//		{
//			if (node->left)
//			{
//				findNode(head, node->left, finded);
//			}
//			if (node->right)
//			{
//				findNode(head, node->right, finded);
//			}
//		}
//
//		if (head->val == node->val && head->next != NULL)//相同
//		{
//			if (node->left)
//			{
//				findNode(head->next, node->left, finded);
//			}
//			if (node->right)
//			{
//				findNode(head->next, node->right, finded);
//			}
//		}
//	}
//};