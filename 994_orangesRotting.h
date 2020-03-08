#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int time = 0;
		int fresh = 0;//����������
		queue<pair<int, int>> Q;
		//��ʼ�����������еĻ����ӷ�����У��������ж��ٺ�����
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

		//���û�к����ӣ�������û�����ӣ�����ֻ�пո�ͻ�����
		if (fresh==0)
		{
			return 0;
		}
		//�������ҵķ�������
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		//�����е����Ӷ�����Ⱦ��Q�л������������Ⱦ�����ӣ�
		//��ʱ��Ϊ�Ѿ�û���������ӣ�����Ҫ����ѭ����
		//����ᵼ�¼�ʱ����1
		while (!Q.empty()&&fresh>0)
		{
			//��¼��ǰ�ж��ٻ�����,����Щ������ȥ��Ⱦ�����ӣ�
			//����Щ�����Ӷ�����һ��֮�󣬼�ʱ+1����Щ�����Ӿ�û���ˣ�
			//��������Ⱦ�������ӣ�
			//ȡ����֮���ǲ������µĻ����ӣ���ʼ������һ�ֵ���Ⱦ
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
						newy < 0 || newy >= grid[newx].size())//ע����grid[newx].size()����Ҫ��д��grid[i].size()
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
		//���������û�б���Ⱦ��
		if (fresh!=0)
		{
			return -1;
		}
		return time;
	}
};