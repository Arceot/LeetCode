#include <vector>
#include <algorithm>
using namespace std;
//��Ŀ��·������С
//������DP ����ÿһ��ÿһ�����С·����ȡ�������Ϻ�������Ŀ��˵�ģ������е�·��ֵ
//ע���жϱ߽磬��Ϊֻ��������������ֱ���жϲ��÷�������Ҳ�ܷ���
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