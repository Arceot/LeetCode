#include <vector>
#include <queue>
using namespace std;
//λ�ú͸߶�
struct Qitem
{
	int x;
	int y;
	int h;
	Qitem(int _x, int _y, int _h) :x(_x), y(_y), h(_h){};
};
//��С�ѵıȽϺ���
struct cmp
{
	bool operator()(const Qitem& a, const Qitem& b)
	{
		return a.h > b.h;
	}

};

//ģ��ˮ������������������ÿ������ĵط�����С�ѣ�������
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		priority_queue<Qitem, vector<Qitem>, cmp> Q;//��С��
		if (heightMap.size()<3 || heightMap[0].size()<3)
		{
			return 0;
		}
		int row = heightMap.size();
		int col = heightMap[0].size();
		//��ʼ��mark���飬���б�Ƿ��ʹ��ĵ�
		vector<vector<int>> mark(row, vector<int>(col));

		//�Ƚ����ܵĵ�push��ȥ
		//��0�к͵�row-1��
		for (int i = 0; i < col;i++)
		{
			Q.push(Qitem(0,i,heightMap[0][i]));
			mark[0][i] = 1;
			Q.push(Qitem(row-1,i,heightMap[row-1][i]));
			mark[row - 1][i] = 1;
		}
		//��0�к͵�col-1��
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
				//�߽�
				if (nx <= 0 || nx >= row - 1 ||
					ny <= 0 || ny >= col - 1||
					mark[nx][ny] == 1)//ע�����mark�÷ź��棬��Ȼ��nx=-1ʱ���ᱨ��������
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