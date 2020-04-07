#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

//别人的方法，很巧妙。陆地一轮一轮地变大，直到所有的海洋都变成陆地。轮数就是距离
//一轮指的是上下左右
//https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/
//这种方法是不是所谓的多源BFS呢？我觉得好像是的
class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int n = grid.size();
		queue<pair<int, int>> q_water;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		int water_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)//遍历每一个格子
			{
				if (grid[i][j]==0)
				{
					water_cnt++;//水总数
				}
			}
		}
		if (water_cnt==0 || water_cnt==n*n)
		{
			return -1;
		}
		int ret = 1;
		while (water_cnt>0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)//遍历每一个格子
				{
					if (grid[i][j]==ret)//初始化的陆地为1，当做原始的第1轮,后面每一轮+1
					{
						for (int k = 0; k < 4; k++)//向上下左右遍历
						{
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
							{
								continue;
							}
							if (grid[nx][ny] == 0)
							{
								grid[nx][ny] = ret+1;//标记为第ret+1轮
								water_cnt--;
							}
						}
					}
				}
			}
			ret++;
		}
		return ret-1;
	}
};

//BFS 超时
//首先遍历所有的海洋，找到他们与陆地的最近距离
//再在这些距离中找一个最大的 
//class Solution {
//public:
//	int maxDistance(vector<vector<int>>& grid) {
//		int n = grid.size();
//		queue<pair<int, int>> q_water;
//		int dx[] = { -1, 1, 0, 0 };
//		int dy[] = { 0, 0, -1, 1 };
//		set<pair<int, int>> set_visit;
//		vector<int> vec_min;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)//遍历每一个格子
//			{
//				if (grid[i][j] == 1)//遇到陆地
//				{
//					continue;
//				}
//				//遇到了水
//				q_water.push(make_pair(i, j));
//				set_visit.insert(make_pair(i, j));
//				while (!q_water.empty())
//				{
//					int x = q_water.front().first;
//					int y = q_water.front().second;
//					q_water.pop();
//					for (int k = 0; k < 4; k++)
//					{
//						int nx = x + dx[k];
//						int ny = y + dy[k];
//						if (nx < 0 || ny < 0 || nx >= n || ny >= n || 
//							set_visit.find(make_pair(nx,ny))!=set_visit.end())
//						{
//							continue;
//						}
//						if (grid[nx][ny] == 1)//遇到陆地
//						{
//							vec_min.push_back(abs(nx - i) + abs(ny - j));
//							q_water=queue<pair<int, int>>();//清空
//							set_visit.clear();
//							break;//退出
//						}
//						if (grid[nx][ny] == 0)//遇到水
//						{
//							q_water.push(make_pair(nx, ny));
//							set_visit.insert(make_pair(nx, ny));
//						}
//					}
//				}
//			}
//		}
//		if (vec_min.size()==0)
//		{
//			return -1;
//		}
//		sort(vec_min.begin(), vec_min.end());
//		return vec_min.back();
//	}
//};

////暴力枚举 超时
////首先遍历所有的海洋，找到他们与陆地的最近距离
////再在这些距离中找一个最大的
//class Solution {
//public:
//	int maxDistance(vector<vector<int>>& grid) {
//		int n = grid.size();
//		vector<pair<int, int>> vec_land;
//		vector<pair<int, int>> vec_water;
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (grid[i][j] == 1)//陆地
//				{
//					vec_land.push_back(make_pair(i, j));
//				}
//				if (grid[i][j] == 0)//水
//				{
//					vec_water.push_back(make_pair(i, j));
//				}
//			}
//		}
//		if (vec_water.size()==0||vec_land.size()==0)
//		{
//			return -1;
//		}
//		int ret = -1;
//		for (int i = 0; i < vec_water.size();i++)
//		{
//			int tmp_len = 2*n;
//			for (int j = 0; j < vec_land.size();j++)
//			{
//				int dis = abs(vec_land[j].first - vec_water[i].first) + 
//					abs(vec_land[j].second - vec_water[i].second);
//				tmp_len = min(tmp_len,dis);
//				if (tmp_len==1)
//				{
//					break;
//				}
//			}
//			ret = max(ret,tmp_len);
//			if (ret==2*n)
//			{
//				break;
//			}
//		}
//		return ret;
//	}
//};

