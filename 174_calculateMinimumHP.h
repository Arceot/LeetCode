#include <vector>
#include <algorithm>
using namespace std;

//�е���˼�������벢�����ӣ���������ᣬ��������
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size()==0)
		{
			return 0;
		}
		int m = dungeon.size();//��
		int n = dungeon[0].size();//��
		vector<vector<int>>dp(m, vector<int>(n, 0));
		dp[m - 1][n - 1] = max(1,1-dungeon[m-1][n-1]);//���½���һ��

		//������Ҫ��������ǰ��ã������ں���ı��������㣬
		//��Ϊ���������ʱ����Ҫ�õ����������ֵ
		//���ұ���һ��
		for (int i = m - 2; i >= 0; i--)
		{
			dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
		}
		//���±���һ��
		for (int i = n - 2; i >= 0; i--)
		{
			dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
		}

		//��������������
		for (int i = m - 2; i >= 0;i--)
		{
			for (int j = n - 2; j >= 0;j--)
			{
				int dp_min = min(dp[i + 1][j], dp[i][j + 1]);//���ƹ�ʽ
				dp[i][j] = max(1,dp_min-dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};