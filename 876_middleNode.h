#include <iostream>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
 public:
	 ListNode* middleNode(ListNode* head) {
		 ListNode* new_head = head;
		 int len = 0;
		 while (new_head)
		 {
			 len++;
			 new_head = new_head->next;
		 }
		 int cnt = len / 2 + 1;
		 new_head = head;
		 cnt--;
		 while (cnt)
		 {
			 new_head = new_head->next;
			 cnt--;
		 }
		 return new_head;
	 }
 };