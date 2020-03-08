#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int time = 0;
		int fresh = 0;//新鲜橘子数
		queue<pair<int, int>> Q;
		//初始遍历，将所有的坏橘子放入队列，并计算有多少好橘子
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 2)
				{
					Q.push(make_pair(i, j));
				}
				if (grid[i][j] == 1)
				{
					fresh++;
				}
			}
		}

		//如果没有好橘子，即表中没有橘子，或者只有空格和坏橘子
		if (fresh==0)
		{
			return 0;
		}
		//上下左右的方向数组
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		//当所有的橘子都被污染后，Q中还残留有最后被污染的橘子，
		//这时因为已经没有新鲜橘子，不需要进入循环，
		//否则会导致计时增加1
		while (!Q.empty()&&fresh>0)
		{
			//记录当前有多少坏橘子,用这些坏橘子去污染好橘子，
			//当这些坏橘子都遍历一遍之后，计时+1，这些坏橘子就没用了，
			//不能再污染其他橘子，
			//取而代之的是产生的新的坏橘子，开始进行下一轮的污染
			int bad = Q.size();
			for (int i = 0; i < bad; i++)
			{
				int x = Q.front().first;
				int y = Q.front().second;
				Q.pop();
				for (int j = 0; j < 4; j++)
				{
					int newx = x + dx[j];
					int newy = y + dy[j];
					if (newx < 0 || newx >= grid.size() ||
						newy < 0 || newy >= grid[newx].size())//注意是grid[newx].size()，不要误写成grid[i].size()
					{
						continue;
					}
					if (grid[newx][newy] == 1)
					{
						grid[newx][newy] = 2;
						fresh--;
						Q.push(make_pair(newx, newy));
					}
				}
			}
			time++;
		}
		//如果好橘子没有被污染完
		if (fresh!=0)
		{
			return -1;
		}
		return time;
	}
};