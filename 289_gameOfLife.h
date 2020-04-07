#include <vector>
using namespace std;
//原地算法
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
		int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
		int m = board.size();//行
		int n = board[m - 1].size();//列
		vector<vector<int>> mark(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int cur_state = board[i][j];
				int live_cnt = 0;
				for (int k = 0; k < 8; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n)
					{
						continue;
					}
					if (board[nx][ny] == 1 || board[nx][ny] == -1)
					{
						live_cnt++;
					}
				}
				if (cur_state == 1)
				{
					if (live_cnt<2 || live_cnt>3)
					{
						board[i][j] = -1;//由活变死 用-1标记
					}
				}
				if (cur_state == 0 && live_cnt == 3)
				{
					board[i][j] = 2;//由死变活 用2标记
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == -1)
				{
					board[i][j] = 0;
				}
				if (board[i][j] == 2)
				{
					board[i][j] = 1;
				}
			}
		}
	}
};

//#include <vector>
//using namespace std;
//class Solution {
//public:
//	void gameOfLife(vector<vector<int>>& board) {
//		int dx[] = {-1,-1,-1,0,1,1,1,0};
//		int dy[] = {-1,0,1,1,1,0,-1,-1};
//		int m = board.size();//行
//		int n = board[m - 1].size();//列
//		vector<vector<int>> mark(m, vector<int>(n, 0));
//		for (int i = 0; i < m;i++)
//		{
//			for (int j = 0; j < n;j++)
//			{
//				int cur_state = board[i][j];
//				int live_cnt = 0;
//				for (int k = 0; k < 8;k++)
//				{
//					int nx = i + dx[k];
//					int ny = j + dy[k];
//					if (nx<0||ny<0||nx>=m||ny>=n)
//					{
//						continue;
//					}
//					if (board[nx][ny]==1)
//					{
//						live_cnt++;
//					}
//				}
//				if (cur_state==1)
//				{
//					if (live_cnt<2 || live_cnt>3)
//					{
//						mark[i][j] = -1;//死亡用-1标记
//					}
//				}
//				if (cur_state==0 && live_cnt==3)
//				{
//					mark[i][j] = 1;//复活用1表示
//				}
//			}
//		}
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (mark[i][j] == -1)
//				{
//					board[i][j] = 0;
//				}
//				if (mark[i][j] == 1)
//				{
//					board[i][j] = 1;
//				}
//			}
//		}
//	}
//};