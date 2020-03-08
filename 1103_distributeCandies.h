#include <vector>
using namespace std;

//画画图，整理下关系就出来了
class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> ret;
		for (int i = 0; i < num_people; i++)
		{
			ret.push_back(0);
		}
		//count表示发了几轮
		int count = 0;
		while (candies>0)
		{
			//遍历每个人
			for (int i = 0; i < num_people; i++)
			{
				// i+1 + num_people*count表示当前这个人应该发多少糖。
				//i表示位置，第0个位置的人，要发1个糖，因此是i+1
				//总共有num_people个人，每一轮每个人相对自己而言要比上次多发num_people*count个
				//如果糖果不够发了
				int more = num_people*count;
				if (candies < i + 1 + more)
				{
					ret[i] += candies;
					candies = 0;
					break;
				}
				//够发就继续发
				ret[i] += i + 1 + more;
				candies -= i + 1 + more;
			}
			count++;
		}
		return ret;
	}
};