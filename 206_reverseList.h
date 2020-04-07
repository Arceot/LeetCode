#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

//����ͷ�巨
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode tmp(0);
		ListNode* next;
		while (head)
		{
			next = head->next;
			head->next = tmp.next;
			tmp.next = head;
			head = next;
		}
		return tmp.next;
	}
};


//��ϰ ����һ��
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		ListNode* new_head=NULL;
//		ListNode* next;
//		while (head)
//		{
//			next = head->next;
//			head->next=new_head;
//			new_head = head;
//			head = next;
//		}
//		return new_head;
//	}
//};

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		ListNode* new_head = NULL;//������Ҫ
//		ListNode* tmp;
//		while (head)
//		{
//			tmp = head->next;
//			head->next = new_head;
//			new_head = head;
//			head = tmp;
//		}
//		return new_head;
//	}
//};

////��ջ
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