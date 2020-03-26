#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int getKth(int lo, int hi, int k) {
		vector<pair<int, int>> vec;
		for (int i = lo; i <= hi;i++)
		{
			int tmp = i;
			int cnt = 0;
			while (tmp!=1)
			{
				if (tmp % 2 == 0)
				{
					tmp = tmp / 2;
					cnt++;
				}
				else
				{
					tmp = 3 * tmp + 1;
					cnt++;
				}
			}
			vec.push_back(make_pair(i, cnt));
		}
		sort(vec.begin(), vec.end(), cmp);
		return vec[k - 1].first;
	}
	//注意这里的排序写法，试了一下，竟然是对的
	static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};