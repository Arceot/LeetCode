#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a,const vector<int>& b){
	return a[0] < b[0];
}

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0){
			return 0;
		}
		sort(points.begin(), points.end(), cmp);//这个排序也以体会下
		int shotBegin = points[0][0];
		int shotEnd = points[0][1];
		int arrowShotNum = 1;
		for (int i = 1; i < points.size(); i++){
			if (shotEnd >= points[i][0]){//思考这里
				shotBegin = points[i][0];
				if (shotEnd>points[i][1]){
					shotEnd = points[i][1];
				}
			}

			else{
				arrowShotNum++;
				shotBegin = points[i][0];
				shotEnd = points[i][1];
			}
		}
		return arrowShotNum;
	}
};