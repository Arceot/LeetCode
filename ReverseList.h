#include<iostream>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* newNode = NULL;
		while (head)
		{
			ListNode* tempNode = head->next;
			head->next =newNode;
			newNode = head;
			head = tempNode;
		}
		return newNode;

	}
};