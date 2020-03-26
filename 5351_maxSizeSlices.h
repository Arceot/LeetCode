#include <vector>
using namespace std;

//还没做完
class Solution {
public:
	int maxSizeSlices(vector<int>& slices) {
		if (slices.size()==3)
		{
			int ret = slices[0];
			for (int i = 0; i < slices.size();i++)
			{
				if (slices[i]>ret)
				{
					ret = slices[i];
				}
			}
			return ret;
		}
		int dp[500] = { 0 };
		dp[0] = slices[0];

	}
};