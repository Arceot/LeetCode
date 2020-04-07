#include <vector>
#include <algorithm>
using namespace std;
//和这题有点像
//https://leetcode-cn.com/problems/trapping-rain-water-ii/
//那道题视频中讲过的。是个三维的，这个题是二维的要简单些
//就是模拟水从两边慢慢地往上涨，遇到坑就把水填进去，
//遇到柱子就涨到和柱子一样高
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size()<=1)
		{
			return 0;
		}
		int max_height = 0, max_index = 0;
		for (int i = 0; i < height.size();i++)//找到最高柱子的位置
		{
			if (height[i]>max_height)
			{
				max_height = height[i];
				max_index = i;
			}
		}
		int water_height = height[0];
		int cnt = 0;
		for (int i = 0; i <= max_index; i++)//从左边往上涨
		{
			if (height[i]<water_height)
			{
				cnt += water_height - height[i];
			}
			if (height[i]>water_height)
			{
				water_height = height[i];
			}
		}
		water_height = height.back();
		for (int i = height.size()-1; i >= max_index; i--)//从右边往上涨
		{
			if (height[i]<water_height)
			{
				cnt += water_height - height[i];
			}
			if (height[i]>water_height)
			{
				water_height = height[i];
			}
		}
		return cnt;
	}
};