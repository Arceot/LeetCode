#include <iostream>
#include <set>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool hasCycle(ListNode *head) {
		std::set<ListNode*> listSet;
		while (head)
		{
			if (listSet.find(head)!=listSet.end())
			{
				return true;
			}
			listSet.insert(head);
			head = head->next;
		}
		return false;
	}
};