#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

//���˵ķ����������½��һ��һ�ֵر��ֱ�����еĺ��󶼱��½�ء��������Ǿ���
//һ��ָ������������
//https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/
//���ַ����ǲ�����ν�Ķ�ԴBFS�أ��Ҿ��ú����ǵ�
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
			for (int j = 0; j < n; j++)//����ÿһ������
			{
				if (grid[i][j]==0)
				{
					water_cnt++;//ˮ����
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
				for (int j = 0; j < n; j++)//����ÿһ������
				{
					if (grid[i][j]==ret)//��ʼ����½��Ϊ1������ԭʼ�ĵ�1��,����ÿһ��+1
					{
						for (int k = 0; k < 4; k++)//���������ұ���
						{
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
							{
								continue;
							}
							if (grid[nx][ny] == 0)
							{
								grid[nx][ny] = ret+1;//���Ϊ��ret+1��
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

//BFS ��ʱ
//���ȱ������еĺ����ҵ�������½�ص��������
//������Щ��������һ������ 
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
//			for (int j = 0; j < n; j++)//����ÿһ������
//			{
//				if (grid[i][j] == 1)//����½��
//				{
//					continue;
//				}
//				//������ˮ
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
//						if (grid[nx][ny] == 1)//����½��
//						{
//							vec_min.push_back(abs(nx - i) + abs(ny - j));
//							q_water=queue<pair<int, int>>();//���
//							set_visit.clear();
//							break;//�˳�
//						}
//						if (grid[nx][ny] == 0)//����ˮ
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

////����ö�� ��ʱ
////���ȱ������еĺ����ҵ�������½�ص��������
////������Щ��������һ������
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
//				if (grid[i][j] == 1)//½��
//				{
//					vec_land.push_back(make_pair(i, j));
//				}
//				if (grid[i][j] == 0)//ˮ
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

