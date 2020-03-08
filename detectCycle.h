#include <iostream>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode * detectCycle(ListNode *head) {
//		std::set<ListNode*> listSet;
//		while (head)
//		{
//			if (listSet.find(head) != listSet.end())
//			{
//				return head;
//			}
//			listSet.insert(head);
//			head = head->next;
//		}
//		return NULL;
//	}
//};

//
//class Solution {
//public:
//	ListNode * detectCycle(ListNode *head) {
//		ListNode* fast=head;
//		ListNode* slow=head;
//		ListNode* meet=NULL;
//		while (fast)
//		{
//			fast = fast->next;
//			slow = slow->next;
//			if (fast==NULL)
//			{
//				return NULL;
//			}
//			fast = fast->next;
//			if (fast==slow)
//			{
//				meet = fast;
//				break;
//			}	
//			
//		}
//		if (meet==NULL)
//		{
//			return NULL;
//		}
//		while (meet && head )
//		{
//			if (meet==head)
//			{
//				return head;
//			}
//			meet = meet->next;
//			head = head->next;
//		}
//		return NULL;
//	}
//};



class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast)
		{
			
			fast = fast->next;	
			if (fast == NULL)
			{
				return NULL;
			}
			fast = fast->next;
			slow = slow->next;//先移动再比较
			if (fast == slow)
			{
				while (head)
				{
					
					if (fast == head)
					{
						return head;
					}
					fast = fast->next;
					head = head->next;
				}
			}
			
		}
		return NULL;
	}
};