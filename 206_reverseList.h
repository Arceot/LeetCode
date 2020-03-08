#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* new_head = NULL;//这里重要
		ListNode* tmp;
		while (head)
		{
			tmp = head->next;
			head->next = new_head;
			new_head = head;
			head = tmp;
		}
		return new_head;
	}
};

////用栈
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (head==NULL)
//		{
//			return NULL;
//		}
//		stack<ListNode*> node_stack;
//		while (head)
//		{
//			node_stack.push(head);
//			head = head->next;
//		}
//		ListNode* newhead;
//		newhead = node_stack.top();
//		node_stack.pop();
//		ListNode* cur = newhead;
//		while (!node_stack.empty())
//		{
//			cur->next = node_stack.top();
//			node_stack.pop();
//			cur = cur->next;
//		}
//		cur->next = NULL;
//		return newhead;
//	}
//};