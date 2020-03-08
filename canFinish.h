#include <vector>
#include <queue>
using namespace std;
struct GraphNode
{
	int lable;
	vector<GraphNode*> neighbors;
	GraphNode(int x) :lable(x) {};
};

//����������� ��� �������
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<GraphNode*> graph;
		vector<int> degree;
		for (int i = 0; i < numCourses; i++)//���������visit
		{
			graph.push_back(new GraphNode(i));
			degree.push_back(0);
		}
		for (int i = 0; i < prerequisites.size(); i++)//������������������
		{
			GraphNode* begin = graph[prerequisites[i][1]];
			GraphNode* end = graph[prerequisites[i][0]];
			begin->neighbors.push_back(end);//��������
			degree[end->lable]++;
		}
		queue<GraphNode*> Q;
		for (int i = 0; i < degree.size();i++)
		{
			if (degree[i]==0)
			{
				Q.push(graph[i]);
			}
		}
		while (!Q.empty())
		{
			GraphNode* node = Q.front();
			Q.pop();
			for (int i = 0; i < node->neighbors.size();i++)
			{
				degree[node->neighbors[i]->lable]--;
				if (degree[node->neighbors[i]->lable]==0)
				{
					Q.push(graph[node->neighbors[i]->lable]);
				}
			}

		}
		for (int i = 0; i < graph.size();i++)//���ﲻҪ������
		{
			delete graph[i];
		}
		for (int i = 0; i < degree.size();i++)//��Ȳ�ȫΪ0�����л�
		{
			if (degree[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};



//�����������
//class Solution {
//public:
//	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//		vector<GraphNode*> graph;
//		vector<int> visit;
//		for (int i = 0; i < numCourses;i++)//���������visit
//		{
//			visit.push_back(-1);
//			graph.push_back(new GraphNode(i));
//		}
//		for (int i = 0; i < prerequisites.size(); i++)//������������������
//		{
//			GraphNode* begin = graph[prerequisites[i][1]];
//			GraphNode* end = graph[prerequisites[i][0]];
//			begin->neighbors.push_back(end);//����������������
//		}
//		for (int i = 0; i < graph.size();i++)
//		{
//			if (visit[i]==-1)
//			{
//				//return ture �����޻���false�����л�
//				if (DFS_graph(graph[i], visit)==false)//falseʱreturn false,true ʱ�Ȳ��ù�
//				{
//					return false;
//				}
//			}
//		}
//		for (int i = 0; i < numCourses;i++)
//		{
//			delete graph[i];
//		}
//		return true;
//
//	}
//private:
//	//�ڵ����״̬��-1����û�з��ʣ�0�������ڷ��ʣ�1����������
//	bool DFS_graph(GraphNode* node, vector<int>& visit)
//	{
//		visit[node->lable] = 0;
//		for (int i = 0; i < node->neighbors.size();i++)
//		{
//			if (visit[node->neighbors[i]->lable] == -1)
//			{
//				if (DFS_graph(node->neighbors[i], visit)==false)//falseʱreturn false,true ʱ�Ȳ��ù�
//				{
//					return false;
//				}
//			}
//			else if (visit[node->neighbors[i]->lable] == 0)//���ﻹ�е�û�����ף�����
//				return false;
//		}
//		visit[node->lable] = 1;
//		return true;
//	}
//};
