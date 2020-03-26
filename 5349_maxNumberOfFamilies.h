#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//ע��n�ǳ���ֱ����n����ͼ����ѭ��n�飬
//����Ҫ���ڴ�ͳ�ʱ
//������
//һ����ల��������ͥ���ܼ����2*n

//��Ҫ�ο����
//https://leetcode-cn.com/problems/cinema-seat-allocation/solution/cha-zhao-by-cieusy/
class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		unordered_map<int, unordered_set<int>> imap;//���������
		for (int i = 0; i < reservedSeats.size(); i++)
		{
			imap[reservedSeats[i][0]].insert(reservedSeats[i][1]);
		}
		int cnt = 0;
		for (auto it : imap)
		{
			int flag = 0;
			if (!it.second.count(2) && !it.second.count(3) &&
				!it.second.count(4) && !it.second.count(5))
			{
				cnt++;
				flag = 1;
			}
			if (!it.second.count(6) && !it.second.count(7) &&
				!it.second.count(8) && !it.second.count(9))
			{
				cnt++;
				flag = 1;
			}
			if (flag==0&&
				!it.second.count(4) && !it.second.count(5) &&
				!it.second.count(6) && !it.second.count(7))
			{
				cnt++;
			}
		}
		return 2 * (n - imap.size()) + cnt;
	}
};


//���ڴ�
//class Solution {
//public:
//	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//		vector<vector<int>> grid(n,vector<int>(10,0));
//		for (int i = 0; i < reservedSeats.size();i++)
//		{
//			grid[reservedSeats[i][0]][reservedSeats[i][1]] = 1;
//		}
//		int cnt = 0;
//		for (int i = 1; i <= n;i++)
//		{
//			int flag = 0;
//			if (grid[i][2]==0&&
//				grid[i][3] == 0 && 
//				grid[i][4] == 0 && 
//				grid[i][5] == 0)
//			{
//				cnt++;
//				flag++;
//			}
//			if (grid[i][6] == 0 &&
//				grid[i][7] == 0 &&
//				grid[i][8] == 0 &&
//				grid[i][9] == 0)
//			{
//				cnt++;
//				flag++;
//			}
//			if (grid[i][4] == 0 &&
//				grid[i][5] == 0 &&
//				grid[i][6] == 0 &&
//				grid[i][7] == 0&&
//				flag==0)
//			{
//				cnt++;
//			}
//		}
//		return cnt;
//	}
//};


//��ʱ
//class Solution {
//public:
//	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//		set<pair<int, int>> mset;
//		for (int i = 0; i < reservedSeats.size(); i++)
//		{
//			mset.insert(make_pair(reservedSeats[i][0], reservedSeats[i][1]));
//		}
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//		{ 
//			int flag = 0;
//			if (mset.find(make_pair(i, 2)) == mset.end()
//				&& mset.find(make_pair(i, 3)) == mset.end()
//				&& mset.find(make_pair(i, 4)) == mset.end()
//				&& mset.find(make_pair(i, 5)) == mset.end())
//			{
//				cnt++;
//				flag++;
//			}
//			if (mset.find(make_pair(i, 6)) == mset.end()
//				&& mset.find(make_pair(i, 7)) == mset.end()
//				&& mset.find(make_pair(i, 8)) == mset.end()
//				&& mset.find(make_pair(i, 9)) == mset.end())
//			{
//				cnt++;
//				flag++;
//			}
//			if (mset.find(make_pair(i, 4)) == mset.end()
//				&& mset.find(make_pair(i, 5)) == mset.end()
//				&& mset.find(make_pair(i, 6)) == mset.end()
//				&& mset.find(make_pair(i, 7)) == mset.end()
//				&& flag == 0)
//			{
//				cnt++;
//			}
//		}
//		return cnt;
//	}
//};