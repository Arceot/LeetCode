#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 class Solution {
 public:
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		 ListNode mergeHead(0);
		 ListNode* newHead = &mergeHead;

		 while (l1 && l2)
		 {
			 if (l1->val < l2->val)
			 {
				 newHead->next = l1;
				 l1 = l1->next;
			 }
			 else
			 {
				 newHead->next = l2;
				 l2 = l2->next;
			 }
			 newHead = newHead->next;
		 }
		 if (l1 != NULL)
		 {
			 newHead->next = l1;
		 }
		 else
		 {
			 newHead->next = l2;
		 }
		 return mergeHead.next;
	 }
 };