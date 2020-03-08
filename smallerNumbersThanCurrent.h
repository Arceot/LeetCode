#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		map<int, int> imap;
		vector<int> re_vec;
		vector<int> sort_nums = nums;
		sort(sort_nums.begin(), sort_nums.end());

		for (int i = 0; i < sort_nums.size(); i++)
		{
			if (imap.find(sort_nums[i])==imap.end())
			{
				imap[sort_nums[i]] = i;
			}
		}
		for (int i = 0; i < nums.size();i++)
		{
			if (imap.find(nums[i])!=imap.end())
			{
				re_vec.push_back(imap[nums[i]]);
			}
		}
		return re_vec;
	}
};