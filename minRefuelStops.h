#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a[0] < b[0];
}
class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		stations.push_back({target, 0});//把终点加入，作为一个停靠点
		sort(stations.begin(), stations.end(), cmp);//按照加油站距离起点的距离，由小到大排序
		priority_queue<int> Q;//最大堆
		int retNum = 0;
		for (int i = 0; i < stations.size(); i++)
		{
			int dis = stations[0][0];
			if (i>0)
			{
				dis = stations[i][0] - stations[i - 1][0];
			}
			while (!Q.empty() && startFuel < dis)
			{
				startFuel += Q.top();
				Q.pop();
				retNum++;
			}
			if (startFuel < dis)//最大堆为空，且当前油量无法到达下一加油点，则无法到达终点
			{
				return -1;
			}
			startFuel = startFuel - dis;//消耗油量，到达下一加油点
			Q.push(stations[i][1]);//将下一加油点的油放入最大堆
		}
		return retNum;
	}
};





//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//bool cmp(const vector<int>& a, const vector<int>& b)
//{
//	return a[0] < b[0];
//}
//class Solution {
//public:
//	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//		stations.push_back({target ,0});//把终点加入，作为一个停靠点
//		sort(stations.begin(), stations.end(), cmp);//按照加油站距离起点的距离，由小到大排序
//		vector<int> disVec;
//		for (int i = 0; i < stations.size();i++)//记录每个停靠点之间的距离
//		{
//			if (i==0)
//				disVec.push_back(stations[0][0]);
//			else
//				disVec.push_back(stations[i][0] - stations[i - 1][0]);
//		}
//		priority_queue<int> Q;//最大堆
//		int retNum = 0;
//		for (int i = 0; i < stations.size(); i++)
//		{
//			while (!Q.empty() && startFuel < disVec[i])//最大堆不为空，且当前油量无法到达下一加油点，则加油
//			{
//				startFuel += Q.top();
//				Q.pop();
//				retNum++;
//			}
//			if (startFuel < disVec[i])//最大堆为空，且当前油量无法到达下一加油点，则无法到达终点
//			{
//				return -1;
//			}
//			startFuel = startFuel - disVec[i];//消耗油量，到达下一加油点
//			Q.push(stations[i][1]);//将下一加油点的油放入最大堆
//		}
//		return retNum;
//	}
//};
