#include<iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		ListNode* result = head;
		int reLength = n - m + 1;
		ListNode* preHead = NULL;
		while (head && --m)
		{
			preHead = head;
			head = head->next;
		}
		ListNode* revedTail = head;
		ListNode* newHead = NULL;
		
		while (head && reLength)
		{
			ListNode* tempHead = head->next;
			head->next = newHead;
			newHead = head;
			head = tempHead;
			reLength--;
		}
		revedTail->next = head;
		if (preHead==NULL)
		{
			result = newHead;
		}
		else
		{
			preHead->next = newHead;
		}
		return result;
	}
	
};


