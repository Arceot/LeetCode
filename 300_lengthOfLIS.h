#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size()<=1){
			return nums.size();
		}
		int cnt = 0;
		int maxcnt = 0;
		int last = nums[0];
		for (int i = 1; i < nums.size();i++){
			if (nums[i]>last){
				cnt++;
				maxcnt = max(maxcnt, cnt);
			}
			else{
				cnt = 0;
			}
		}
		return maxcnt;
	}
};