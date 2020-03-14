#include <vector>
#include <queue>
using namespace std;
//位置和高度
struct Qitem
{
	int x;
	int y;
	int h;
	Qitem(int _x, int _y, int _h) :x(_x), y(_y), h(_h){};
};
//最小堆的比较函数
struct cmp
{
	bool operator()(const Qitem& a, const Qitem& b)
	{
		return a.h > b.h;
	}

};

//模拟水在外面慢慢往里流，每次在最矮的地方（最小堆）往里流
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		priority_queue<Qitem, vector<Qitem>, cmp> Q;//最小堆
		if (heightMap.size()<3 || heightMap[0].size()<3)
		{
			return 0;
		}
		int row = heightMap.size();
		int col = heightMap[0].size();
		//初始化mark数组，进行标记访问过的点
		vector<vector<int>> mark(row, vector<int>(col));

		//先将四周的点push进去
		//第0行和第row-1行
		for (int i = 0; i < col;i++)
		{
			Q.push(Qitem(0,i,heightMap[0][i]));
			mark[0][i] = 1;
			Q.push(Qitem(row-1,i,heightMap[row-1][i]));
			mark[row - 1][i] = 1;
		}
		//第0列和第col-1列
		for (int i = 1; i < row - 1;i++)
		{
			Q.push(Qitem(i,0,heightMap[i][0]));
			mark[i][0] = 1;
			Q.push(Qitem(i, col - 1, heightMap[i][col - 1]));
			mark[i][col - 1] = 1;
		}

		//BFS
		int cnt = 0;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		while (!Q.empty())
		{
			Qitem node = Q.top();
			int x = node.x;
			int y = node.y;
			int h = node.h;
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				//cout << "nx=" << nx << " ny=" << ny << endl;
				//边界
				if (nx <= 0 || nx >= row - 1 ||
					ny <= 0 || ny >= col - 1||
					mark[nx][ny] == 1)//注意这个mark得放后面，不然当nx=-1时，会报索引错误
				{
					continue;
				}
				if (heightMap[nx][ny]<h)
				{
					cnt += h - heightMap[nx][ny];
					heightMap[nx][ny] = h;
				}
				mark[nx][ny] = 1;
				Q.push(Qitem(nx, ny, heightMap[nx][ny]));
			}
		}
		return cnt;
	}
};