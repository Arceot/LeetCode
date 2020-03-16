#include <vector>
#include <algorithm>
using namespace std;
//自己写得从上往下推，视频里的是从下往上推，从下到上的好处是，不用考虑越界的问题
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//for (int i = 0; i < triangle.size();i++)
		//{
		//	for (int j = 0; j < triangle[i].size();j++)
		//	{
		//		cout << triangle[i][j]<<" ";
		//	}
		//	cout << endl;
		//}
		int dx[] = { -1 ,-1};//下一层的向上访问上一层的，正上，上左，注意不能对上右访问
		int dy[] = {0,-1};
		vector<int> tmp;
		for (int i =1; i < triangle.size();i++ )
		{
			for (int j = 0;j<triangle[i].size();j++)
			{
				for (int k = 0; k < 2;k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (ny<0||ny>=triangle[i-1].size())//越界
					{
						continue;
					}
					tmp.push_back(triangle[nx][ny]);
				}
				sort(tmp.begin(), tmp.end());
				triangle[i][j] += tmp[0];
				tmp.clear();
			}
		}
		//for (int i = 0; i < triangle.size(); i++)
		//{
		//	for (int j = 0; j < triangle[i].size(); j++)
		//	{
		//		cout << triangle[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		int ret = INT_MAX;
		for (int i = 0; i < triangle[triangle.size() - 1].size();i++)
		{
			ret = min(ret, triangle[triangle.size() - 1][i]);
		}
		return ret;
	}
};