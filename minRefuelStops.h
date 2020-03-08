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
		stations.push_back({target, 0});//���յ���룬��Ϊһ��ͣ����
		sort(stations.begin(), stations.end(), cmp);//���ռ���վ�������ľ��룬��С��������
		priority_queue<int> Q;//����
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
			if (startFuel < dis)//����Ϊ�գ��ҵ�ǰ�����޷�������һ���͵㣬���޷������յ�
			{
				return -1;
			}
			startFuel = startFuel - dis;//����������������һ���͵�
			Q.push(stations[i][1]);//����һ���͵���ͷ�������
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
//		stations.push_back({target ,0});//���յ���룬��Ϊһ��ͣ����
//		sort(stations.begin(), stations.end(), cmp);//���ռ���վ�������ľ��룬��С��������
//		vector<int> disVec;
//		for (int i = 0; i < stations.size();i++)//��¼ÿ��ͣ����֮��ľ���
//		{
//			if (i==0)
//				disVec.push_back(stations[0][0]);
//			else
//				disVec.push_back(stations[i][0] - stations[i - 1][0]);
//		}
//		priority_queue<int> Q;//����
//		int retNum = 0;
//		for (int i = 0; i < stations.size(); i++)
//		{
//			while (!Q.empty() && startFuel < disVec[i])//���Ѳ�Ϊ�գ��ҵ�ǰ�����޷�������һ���͵㣬�����
//			{
//				startFuel += Q.top();
//				Q.pop();
//				retNum++;
//			}
//			if (startFuel < disVec[i])//����Ϊ�գ��ҵ�ǰ�����޷�������һ���͵㣬���޷������յ�
//			{
//				return -1;
//			}
//			startFuel = startFuel - disVec[i];//����������������һ���͵�
//			Q.push(stations[i][1]);//����һ���͵���ͷ�������
//		}
//		return retNum;
//	}
//};
