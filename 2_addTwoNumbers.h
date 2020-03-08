#include <stack>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode rl(0);
		ListNode* head = &rl;
		int flag = 0;//�Ƿ��λ��flag
		//��ǰ��������������
		while (l1 && l2)
		{
			int sum = l1->val + l2->val;
			head->next = new ListNode((sum+flag)%10);
			if (sum+flag>=10)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
			head = head->next;
		}
		//��l1��l2��ʱ������ʣ���l1
		while (l1)
		{
			head->next = new ListNode((l1->val + flag) % 10);
			if (l1->val+flag>=10)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			l1 = l1->next;
			head = head->next;
		}
		//��l2��l1��ʱ������ʣ���l2
		while (l2)
		{
			head->next = new ListNode((l2->val + flag) % 10);
			if (l2->val + flag >= 10)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			l2 = l2->next;
			head = head->next;
		}
		//��l1��l2�����������flagΪ1����flag����
		if (flag==1)
		{
			head->next = new ListNode(flag);
		}
		return rl.next;
	}
};



////�븴����
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		queue<int> q1;
//		queue<int> q2;
//		queue<int> rq;
//		int len1=0;
//		int len2=0;
//		while (l1)
//		{
//			q1.push(l1->val);
//			l1 = l1->next;
//			len1++;
//		}
//		while (l2)
//		{
//			q2.push(l2->val);
//			l2 = l2->next;
//			len2++;
//		}
//		int short_length = len1;
//		if (len2<len1)
//		{
//			short_length = len2;
//		}
//		int flag = 0;
//		//��λ�ۼ�
//		if (short_length>0)
//		{
//			for (int i = 0; i < short_length; i++)
//			{
//				int sum = q1.front() + q2.front();
//				rq.push((sum + flag) % 10);
//				if (sum + flag >= 10)
//					flag = 1;
//				else
//					flag = 0;
//				q1.pop();
//				q2.pop();
//			}
//		}
//		while (!q1.empty())
//		{
//			rq.push((q1.front()+flag)%10);
//			if (q1.front() + flag>=10)
//			{
//				flag = 1;
//			}
//			else
//			{
//				flag = 0;
//			}
//			q1.pop();
//		}
//		while (!q2.empty())
//		{
//			rq.push((q2.front() + flag) % 10);
//			if (q2.front() + flag >= 10)
//			{
//				flag = 1;
//			}
//			else
//			{
//				flag = 0;
//			}
//			q2.pop();
//		}
//		if (flag==1)
//		{
//			rq.push(flag);
//		}
//		ListNode rl(0);
//		ListNode* head = &rl;
//		while (!rq.empty())
//		{
//			head->next = new ListNode(rq.front());
//			rq.pop();
//			head=head->next;
//		}
//		return rl.next;
//	}
//};