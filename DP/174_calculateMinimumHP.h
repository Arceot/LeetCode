#include <vector>
#include <algorithm>
using namespace std;

//有点难思考，代码并不复杂，得慢慢体会，消化消化
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size()==0)
		{
			return 0;
		}
		int m = dungeon.size();//行
		int n = dungeon[0].size();//列
		vector<vector<int>>dp(m, vector<int>(n, 0));
		dp[m - 1][n - 1] = max(1,1-dungeon[m-1][n-1]);//右下角那一格

		//这两段要在外面提前算好，不能在后面的遍历里面算，
		//因为后面遍历的时候需要用到这里算出的值
		//最右边那一列
		for (int i = m - 2; i >= 0; i--)
		{
			dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
		}
		//最下边那一行
		for (int i = n - 2; i >= 0; i--)
		{
			dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
		}

		//从右下往左上推
		for (int i = m - 2; i >= 0;i--)
		{
			for (int j = n - 2; j >= 0;j--)
			{
				int dp_min = min(dp[i + 1][j], dp[i][j + 1]);//递推公式
				dp[i][j] = max(1,dp_min-dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};