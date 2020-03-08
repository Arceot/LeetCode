#include <vector>
#include <queue>
using namespace std;

//视频里的方法mark矩阵用于标记，
//还有一种方法，在后面写得
//直接将grid矩阵的1改为不是1，比如2用于标记访问过的位置
//class Solution {
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		vector<vector<int>> mark;
//		int island_num = 0;
//		//初始化mark和grid的大小一致，且值为0
//		for (int i = 0; i < grid.size(); i++)
//		{
//			mark.push_back(vector<int>());
//			for (int j = 0; j < grid[i].size(); j++)
//			{
//				mark[i].push_back(0);
//			}
//		}
//		//遍历grid
//		for (int i = 0; i < grid.size(); i++)
//		{
//			for (int j = 0; j < grid[i].size(); j++)
//			{
//				//如果遇到了一个陆地，且没有被标记访问过
//				if (grid[i][j] == '1' && mark[i][j] == 0)
//				{
//					//深搜或者宽搜，访问与这块陆地相连的全部位置并标记为1
//					//DFS(grid, mark, i, j);
//					BFS(grid, mark, i, j);
//					//搜索完成后即找到了一个岛屿
//					island_num++;
//				}
//			}
//		}
//		return island_num;
//
//	}
//private:
//	//深搜
//	void DFS(vector<vector<char>>& grid, vector<vector<int>>& mark, int x, int y)
//	{
//		mark[x][y] = 1;
//		//上下左右的方向数组
//		static const int dx[] = { -1, 1, 0, 0 };
//		static const int dy[] = { 0, 0, -1, 1 };
//		//深搜
//		for (int i = 0; i < 4;i++)
//		{
//			int newx = x + dx[i];
//			int newy = y + dy[i];
//			//控制不要越界
//			if (newx<0 || newx>=grid.size()||//注意这里是>=而不是>
//				newy<0||newy>=grid[newx].size())
//			{
//				continue;
//			}
//			if (grid[newx][newy]=='1' && mark[newx][newy]==0)
//			{
//				DFS(grid, mark, newx, newy);
//			}
//		}
//	}
//
//	//宽搜
//	void BFS(vector<vector<char>>& grid, vector<vector<int>>& mark, int x, int y)
//	{
//		//用队列存储坐标
//		queue<pair<int,int>> Q;
//		Q.push(make_pair(x, y));
//		mark[x][y] = 1;
//		//上下左右的方向数组
//		static const int dx[] = { -1, 1, 0, 0 };
//		static const int dy[] = { 0, 0, -1, 1 };
//		while (!Q.empty())
//		{
//			x = Q.front().first;
//			y = Q.front().second;
//			Q.pop();
//			for (int i = 0; i < 4; i++)//拓展四个方向
//			{
//				int newx = x + dx[i];
//				int newy = y + dy[i];
//
//				if (newx<0 || newx>=grid.size() ||
//					newy<0 || newy>=grid[newx].size())
//				{
//					continue;
//				}
//				if (grid[newx][newy] == '1' && mark[newx][newy] == 0)
//				{
//					Q.push(make_pair(newx, newy));//将新位置push进队列
//					mark[newx][newy] = 1;//并标记
//				}
//			}
//		}
//	}
//
//};


//访问过的标记为‘2’
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int island_num = 0;
		//遍历grid
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				//如果遇到了一个陆地，且没有被标记访问过
				if (grid[i][j] == '1')
				{
					DFS(grid, i, j);
					BFS(grid, i, j);
					island_num++;
				}
			}
		}
		return island_num;

	}
private:
	//深搜
	void DFS(vector<vector<char>>& grid, int x, int y)
	{
		grid[x][y] = '2';
		//上下左右的方向数组
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		//深搜
		for (int i = 0; i < 4; i++)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			//控制不要越界
			if (newx < 0 || newx >= grid.size() ||//注意这里是>=而不是>
				newy < 0 || newy >= grid[newx].size())
			{
				continue;
			}
			if (grid[newx][newy] == '1')
			{
				DFS(grid,newx, newy);
			}
		}
	}

	//宽搜
	void BFS(vector<vector<char>>& grid,int x, int y)
	{
		//用队列存储坐标
		queue<pair<int, int>> Q;
		Q.push(make_pair(x, y));
		grid[x][y] = '2';
		//上下左右的方向数组
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		while (!Q.empty())
		{
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++)//拓展四个方向
			{
				int newx = x + dx[i];
				int newy = y + dy[i];

				if (newx < 0 || newx >= grid.size() ||
					newy < 0 || newy >= grid[newx].size())
				{
					continue;
				}
				if (grid[newx][newy] == '1')
				{
					Q.push(make_pair(newx, newy));//将新位置push进队列
					grid[newx][newy] = '2';//并标记
				}
			}
		}
	}

};