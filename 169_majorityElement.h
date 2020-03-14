#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> mp;
		int maxcnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			mp[nums[i]]++;
			if (mp[nums[i]]>maxcnt)
			{
				maxcnt = mp[nums[i]];
				if (maxcnt > nums.size() / 2)
				{
					return nums[i];
				}
			}
		}
		return 0;
	}
};