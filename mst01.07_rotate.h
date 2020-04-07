#include <vector>
#include <algorithm>
using namespace std;

//转置
//交换列（即每行两边的点对换）
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n==0)
		{
			return;
		}
		//转置（即，以左上右下为对角线旋转）
		for (int i = 0; i < n;i++)
		{
			for (int j = i; j < n;j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
		//交换
		int mid = n / 2;
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < mid;j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = tmp;
			}
		}
	}
};