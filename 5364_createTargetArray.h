#include <vector>
using namespace std;

//本来想用链表做的，觉得那样可以快一些，
//但是在insert那里总是报错，还没找到原因
//厚礼看了别人的vector，于是又改为了vector
class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			ret.insert(ret.begin() + index[i], nums[i]);
		}
		return ret;
	}
};