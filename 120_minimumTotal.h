#include <vector>
#include <algorithm>
using namespace std;
//�Լ�д�ô��������ƣ���Ƶ����Ǵ��������ƣ����µ��ϵĺô��ǣ����ÿ���Խ�������
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
		int dx[] = { -1 ,-1};//��һ������Ϸ�����һ��ģ����ϣ�����ע�ⲻ�ܶ����ҷ���
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
					if (ny<0||ny>=triangle[i-1].size())//Խ��
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