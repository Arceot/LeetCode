#include <iostream>
#include <vector>
#include <algorithm>


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//法1 先将所有节点放入vector，再排序，再连接
//bool cmp(const ListNode* a,const ListNode* b)
//{
//	return a->val < b->val;
//}
//
//class Solution {
//public:
//	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
//		std::vector<ListNode*> valVector;
//		for (int i=0; i < lists.size();i++)
//		{
//			while (lists[i])
//			{
//				valVector.push_back(lists[i]);
//				lists[i]=lists[i]->next;
//			}
//		}
//		if (valVector.size()==0)
//		{
//			return NULL;
//		}
//		//将指针对应的数据进行排序，具体百度sort和cmp的使用
//		std::sort(valVector.begin(), valVector.end(),cmp);
//		for (int i = 1; i < valVector.size();i++)
//		{
//			valVector[i - 1]->next = valVector[i];
//		}
//		valVector[valVector.size() - 1]->next = NULL;
//		return valVector[0];
//	}
//};


//法2 分治算法
class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		if (lists.size() == 0)
		{
			return NULL;
		}
		if (lists.size() == 1)
		{
			return lists[0];
		}
		if (lists.size() == 2)
		{
			return mergeTwoLists(lists[0], lists[1]);
		}
		int mid = lists.size() / 2;
		std::vector<ListNode*> list1;
		std::vector<ListNode*> list2;

		for (int i = 0; i < mid; i++)
		{
			list1.push_back(lists[i]);
		}
		for (int i = mid; i < lists.size(); i++)
		{
			list2.push_back(lists[i]);
		}
		return mergeTwoLists(mergeKLists(list1), mergeKLists(list2));
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode mergeHead(0);
		ListNode* newHead = &mergeHead;

		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				newHead->next = list1;
				list1 = list1->next;
			}
			else
			{
				newHead->next = list2;
				list2 = list2->next;
			}
			newHead = newHead->next;
		}
		if (list1 != NULL)
		{
			newHead->next = list1;
		}
		else
		{
			newHead->next = list2;
		}
		return mergeHead.next;
	}
};
