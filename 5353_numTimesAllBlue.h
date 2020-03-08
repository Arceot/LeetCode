#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int num = 0;
		int min = light[0];
		int max = light[0];
		//k时刻打开light[k]这个灯,light[k]是灯的位置
		for (int k = 0; k < light.size();k++)
		{
			if (light[k]<min)
			{
				min = light[k];
			}
			if (light[k]>max)
			{
				max = light[k];
			}
			//下面这一段可以不要，要的话快一些
			//k时刻打开了k+1个灯，
			//所以这是打开灯的位置如果是大于k+1
			//那么肯定不会变蓝
			//if (light[k]>k+1)
			//{
			//	continue;
			//}
			if (min == 1 && max == k + 1)
			{
				//cout << light[k] << " ";
				num++;
			}
		}
		return num;
	}
};