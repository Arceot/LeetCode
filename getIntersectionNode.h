#include<iostream>
#include<set>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//内存消耗大，耗时短
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		std::set<ListNode *> nodeSet;
//		while (headA)
//		{
//			nodeSet.insert(headA);
//			headA = headA->next;
//		}
//		while (headB)
//		{
//			if (nodeSet.find(headB)!=nodeSet.end())
//			{
//				return headB;
//			}
//			headB=headB->next;
//		}
//		return NULL;
//	}
//};


//内存消耗小，耗时长
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int lengthA = getLength(headA);
		int lengthB = getLength(headB);
		if (lengthA > lengthB)
		{
			int i = lengthA - lengthB;
			return getSame(i,headA,headB,lengthB);	
		}
		else
		{
			int i = lengthB - lengthA;
			return getSame(i, headB, headA, lengthA);
		}
	};
	int getLength(ListNode *headA)
	{
		int length = 0;
		while (headA)
		{
			length++;
			headA = headA->next;
		}
		return length;
	}
	ListNode * getSame(int more, ListNode * lenList, ListNode *shortList,int shortListLength)
	{
		while (more--)
		{
			lenList = lenList->next;
		}
		for (int more = 0; more < shortListLength; more++)
		{
			if (lenList == shortList)
			{
				return lenList;
			}
			lenList = lenList->next;
			shortList = shortList->next;
		}
		return NULL;
	}

};