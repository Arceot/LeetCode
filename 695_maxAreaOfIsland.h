#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//BFS
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.size() == 0)
		{
			return 0;
		}
		int cntmax = 0;
		queue<pair<int, int>> Q;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					Q.push(make_pair(i, j));
					grid[i][j] = 0;//访问过的置为0,注意是=不是==。。。。。。。。
					int cnt = 1;
					while (!Q.empty())
					{
						int x = Q.front().first;
						int y = Q.front().second;
						Q.pop();
						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || nx >= grid.size()
								||ny < 0 || ny >= grid[0].size()
								|| grid[nx][ny] == 0)
							{
								continue;
							}
							if (grid[nx][ny] == 1)
							{
								Q.push(make_pair(nx, ny));
								grid[nx][ny] = 0;
								cnt++;
							}
						}
					}
					cntmax = max(cnt, cntmax);
				}
			}
		}
		return cntmax;
	}
};