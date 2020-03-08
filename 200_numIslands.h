#include <vector>
#include <queue>
using namespace std;

//��Ƶ��ķ���mark�������ڱ�ǣ�
//����һ�ַ������ں���д��
//ֱ�ӽ�grid�����1��Ϊ����1������2���ڱ�Ƿ��ʹ���λ��
//class Solution {
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		vector<vector<int>> mark;
//		int island_num = 0;
//		//��ʼ��mark��grid�Ĵ�Сһ�£���ֵΪ0
//		for (int i = 0; i < grid.size(); i++)
//		{
//			mark.push_back(vector<int>());
//			for (int j = 0; j < grid[i].size(); j++)
//			{
//				mark[i].push_back(0);
//			}
//		}
//		//����grid
//		for (int i = 0; i < grid.size(); i++)
//		{
//			for (int j = 0; j < grid[i].size(); j++)
//			{
//				//���������һ��½�أ���û�б���Ƿ��ʹ�
//				if (grid[i][j] == '1' && mark[i][j] == 0)
//				{
//					//���ѻ��߿��ѣ����������½��������ȫ��λ�ò����Ϊ1
//					//DFS(grid, mark, i, j);
//					BFS(grid, mark, i, j);
//					//������ɺ��ҵ���һ������
//					island_num++;
//				}
//			}
//		}
//		return island_num;
//
//	}
//private:
//	//����
//	void DFS(vector<vector<char>>& grid, vector<vector<int>>& mark, int x, int y)
//	{
//		mark[x][y] = 1;
//		//�������ҵķ�������
//		static const int dx[] = { -1, 1, 0, 0 };
//		static const int dy[] = { 0, 0, -1, 1 };
//		//����
//		for (int i = 0; i < 4;i++)
//		{
//			int newx = x + dx[i];
//			int newy = y + dy[i];
//			//���Ʋ�ҪԽ��
//			if (newx<0 || newx>=grid.size()||//ע��������>=������>
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
//	//����
//	void BFS(vector<vector<char>>& grid, vector<vector<int>>& mark, int x, int y)
//	{
//		//�ö��д洢����
//		queue<pair<int,int>> Q;
//		Q.push(make_pair(x, y));
//		mark[x][y] = 1;
//		//�������ҵķ�������
//		static const int dx[] = { -1, 1, 0, 0 };
//		static const int dy[] = { 0, 0, -1, 1 };
//		while (!Q.empty())
//		{
//			x = Q.front().first;
//			y = Q.front().second;
//			Q.pop();
//			for (int i = 0; i < 4; i++)//��չ�ĸ�����
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
//					Q.push(make_pair(newx, newy));//����λ��push������
//					mark[newx][newy] = 1;//�����
//				}
//			}
//		}
//	}
//
//};


//���ʹ��ı��Ϊ��2��
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int island_num = 0;
		//����grid
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				//���������һ��½�أ���û�б���Ƿ��ʹ�
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
	//����
	void DFS(vector<vector<char>>& grid, int x, int y)
	{
		grid[x][y] = '2';
		//�������ҵķ�������
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		//����
		for (int i = 0; i < 4; i++)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			//���Ʋ�ҪԽ��
			if (newx < 0 || newx >= grid.size() ||//ע��������>=������>
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

	//����
	void BFS(vector<vector<char>>& grid,int x, int y)
	{
		//�ö��д洢����
		queue<pair<int, int>> Q;
		Q.push(make_pair(x, y));
		grid[x][y] = '2';
		//�������ҵķ�������
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		while (!Q.empty())
		{
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++)//��չ�ĸ�����
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
					Q.push(make_pair(newx, newy));//����λ��push������
					grid[newx][newy] = '2';//�����
				}
			}
		}
	}

};