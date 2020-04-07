#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findLucky(vector<int>& arr) {
		int imap[500] = { 0 };
		for (auto& i:arr)
		{
			imap[i]++;
		}
		int ret = -1;
		for (int i = 1; i < 500;i++)
		{
			if (i==imap[i])
			{
				ret = max(ret, i);
			}
		}
		return ret;
	}
};