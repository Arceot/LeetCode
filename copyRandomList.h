#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};


class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, int> nodeMap;
		vector<Node*> nodeVector;
		Node* ptr = head;
		int i = 0;
		while (ptr)
		{
			nodeVector.push_back(new Node(ptr->val));
			nodeMap[ptr] = i;
			ptr = ptr->next;
			i++;
		}
		nodeVector.push_back(0);
		ptr = head;
		i = 0;
		while (ptr)
		{
			nodeVector[i]->next = nodeVector[i+1];
			if (ptr->random)
			{
				int id = nodeMap[ptr->random];
				nodeVector[i]->random = nodeVector[id];
			}
			ptr = ptr->next;
			i++;
		}
		return nodeVector[0];
	}
};