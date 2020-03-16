#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		set<int> mset;
		int m = matrix.size();//ÐÐ
		int n = matrix[0].size();//ÁÐ
		vector<int> ret;
		for (int i = 0; i <m;i++)
		{
			int hmin = matrix[i][0];
			for (int j = 0; j < n;j++)
			{
				hmin = min(hmin,matrix[i][j]);
			}
			mset.insert(hmin);
		}
		for (int i = 0; i < n;i++)
		{
			int vmax = matrix[0][i];
			for (int j = 0; j < m;j++)
			{
				vmax = max(vmax,matrix[j][i]);
			}
			if (mset.find(vmax)!=mset.end())
			{
				ret.push_back(vmax);
			}
		}
		return ret;
	}
};