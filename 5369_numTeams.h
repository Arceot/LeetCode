#include <vector>
using namespace std;

//����Ϊ�ᳬʱ����Ȼͨ���ˣ����滹��һ�ֱ��˵Ķ�̬�滮�㷨���ǳ���
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
				int up = 0;//�½�
				if (rating[j]>rating[i])
				{
					up = 1;//����
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

//����д�ö�̬�滮�㷨���ǳ���
//���ӣ�https://leetcode-cn.com/problems/count-number-of-teams/solution/dp-shuang-bai-by-zhi-dang-cun-gao-yuan-3/
//dp1[i][0]�ŵ�����i��߱�rating[i]С����Ŀ
//dp1[i][1]�ŵ�����i�ұ߱�rating[i]�����Ŀ
//dp2[i][0]�ŵ�����i��߱�rating[i]�����Ŀ
//dp2[i][1]�ŵ�����i�ұ߱�rating[i]С����Ŀ

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