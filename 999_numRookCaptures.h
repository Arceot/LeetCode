#include <vector>
using namespace std;

//°×³µR ¿Õ·½¿é. °×ÏóB ºÚ×äp
class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int x = 0;
		int y = 0;
		for (int i = 0; i < 8;i++)
		{
			for (int j = 0; j < 8;j++)
			{
				if (board[i][j]=='R')
				{
					x = i;
					y = j;
				}
			}
		}
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		int cnt = 0;
		for (int i = 0; i < 4;i++)
		{
			for (int j = 0; j < 8;j++)
			{
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;
				if (nx < 0 || ny < 0 ||
					nx >= 8 || ny >= 8)
				{
					continue;
				}
				if (board[nx][ny]=='B')
				{
					break;
				}
				if (board[nx][ny] == 'p')
				{
					cnt++;
					break;
				}
			}
		}
		return cnt;
	}
};