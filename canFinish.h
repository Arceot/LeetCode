#include <vector>
#include <queue>
using namespace std;
struct GraphNode
{
	int lable;
	vector<GraphNode*> neighbors;
	GraphNode(int x) :lable(x) {};
};

//广度优先搜索 入度 入度数组
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<GraphNode*> graph;
		vector<int> degree;
		for (int i = 0; i < numCourses; i++)//创建顶点和visit
		{
			graph.push_back(new GraphNode(i));
			degree.push_back(0);
		}
		for (int i = 0; i < prerequisites.size(); i++)//将顶点有向连接起来
		{
			GraphNode* begin = graph[prerequisites[i][1]];
			GraphNode* end = graph[prerequisites[i][0]];
			begin->neighbors.push_back(end);//建立连接
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
		for (int i = 0; i < graph.size();i++)//这里不要忘记了
		{
			delete graph[i];
		}
		for (int i = 0; i < degree.size();i++)//入度不全为0，则有环
		{
			if (degree[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};



//深度优先搜索
//class Solution {
//public:
//	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//		vector<GraphNode*> graph;
//		vector<int> visit;
//		for (int i = 0; i < numCourses;i++)//创建顶点和visit
//		{
//			visit.push_back(-1);
//			graph.push_back(new GraphNode(i));
//		}
//		for (int i = 0; i < prerequisites.size(); i++)//将顶点有向连接起来
//		{
//			GraphNode* begin = graph[prerequisites[i][1]];
//			GraphNode* end = graph[prerequisites[i][0]];
//			begin->neighbors.push_back(end);//有向连接两个顶点
//		}
//		for (int i = 0; i < graph.size();i++)
//		{
//			if (visit[i]==-1)
//			{
//				//return ture 代表无环，false代表有环
//				if (DFS_graph(graph[i], visit)==false)//false时return false,true 时先不用管
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
//	//节点访问状态，-1代表没有访问，0代表正在访问，1代表访问完成
//	bool DFS_graph(GraphNode* node, vector<int>& visit)
//	{
//		visit[node->lable] = 0;
//		for (int i = 0; i < node->neighbors.size();i++)
//		{
//			if (visit[node->neighbors[i]->lable] == -1)
//			{
//				if (DFS_graph(node->neighbors[i], visit)==false)//false时return false,true 时先不用管
//				{
//					return false;
//				}
//			}
//			else if (visit[node->neighbors[i]->lable] == 0)//这里还有点没想明白！！！
//				return false;
//		}
//		visit[node->lable] = 1;
//		return true;
//	}
//};
