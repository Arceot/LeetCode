#include <vector>
using namespace std;

//本以为会超时，竟然通过了，后面还有一种别人的动态规划算法，非常快
class Solution {
public:
	int numTeams(vector<int>& rating) {
		int n = rating.size();
		if (n<3)
		{
			return 0;
		}
		int cnt = 0;

		for (int i = 0; i < n - 2; i++)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				int up = 0;//下降
				if (rating[j]>rating[i])
				{
					up = 1;//上升
				}
				for (int k = j + 1; k < n; k++)
				{
					if (rating[k]>rating[j] && up==1)
					{
						cnt++;
					}
					if (rating[k]<rating[j] && up == 0)
					{
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
};

//别人写得动态规划算法，非常快
//链接：https://leetcode-cn.com/problems/count-number-of-teams/solution/dp-shuang-bai-by-zhi-dang-cun-gao-yuan-3/
//dp1[i][0]放得是在i左边比rating[i]小的数目
//dp1[i][1]放得是在i右边比rating[i]大的数目
//dp2[i][0]放得是在i左边比rating[i]大的数目
//dp2[i][1]放得是在i右边比rating[i]小的数目

class Solution {
public:
	int numTeams(vector<int>& rating) {
		if (rating.size() < 3)return 0;
		int dp1[200][2] = { 0 }, dp2[200][2] = { 0 };
		for (int i = 1; i < rating.size(); i++){
			for (int j = 0; j < i; j++){
				if (rating[j] < rating[i]){
					dp1[i][0]++;
					dp1[j][1]++;
				}
				else{
					dp2[i][0]++;
					dp2[j][1]++;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < rating.size() - 1; i++)ans += dp1[i][0] * dp1[i][1] + dp2[i][0] * dp2[i][1];
		return ans;
	}
};