#include <vector>
#include <algorithm>
using namespace std;
//题目：路径和最小
//方法：DP 遍历每一格，每一格的最小路径和取决于其上和其左（题目中说的）格子中的路径值
//注意判断边界，因为只有两个方向，所以直接判断不用方向数组也很方便
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		//vector<vector<int>> mark(grid.size(),vector<int>(grid[0].size(),0))
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (i-1<0)
				{
					if (j-1<0)
						continue;
					else
						grid[i][j] += grid[i][j - 1];
				}
				else
				{
					if (j - 1 < 0)
						grid[i][j] += grid[i - 1][j];
					else
						grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
				}
			}
		}
		return grid[grid.size()-1][grid[0].size()-1];
	}
};