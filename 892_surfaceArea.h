#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int n = grid.size();
		int area = 0;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a = grid[i][j];
				if (a == 0)
				{
					continue;
				}
				//area += 6 * a - (a - 1) * 2;
				area += 4 * a +2;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					{
						continue;
					}
					area -= min(a, grid[nx][ny]);
				}
			}
		}
		return area;
	}
};