#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		//cout << "entering..." << endl;
		if (z>x+y)
		{
			return false;
		}
		int full_x = x;
		int full_y = y;
		unordered_set <size_t> iset;
		queue<pair<int, int>> Q;
		Q.push(make_pair(x, y));
		while (!Q.empty())
		{
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			/********/
			//std::unordered_set 是基于hash实现的。
			//std::set 是基于红黑树实现的。
			size_t key = (size_t)x * 100000007 + y;
			if (iset.find(key) != iset.end())//如果之前访问过了就退出
			{
				continue;
			}
			iset.insert(key);
			/********/

			if (x==z||y==z||x+y==z)
			{
				return true;
			}
			
			Q.push(make_pair(full_x, y));//x加满
			Q.push(make_pair(0, y));//x倒空
			Q.push(make_pair(x + y - min(full_y, x + y), min(full_y, x + y)));//x倒入y中，直到y中倒满或者x倒空

			Q.push(make_pair(x, full_y));//y加满
			Q.push(make_pair(x, 0));//y倒空
			Q.push(make_pair(min(full_x, x + y), x + y - min(full_x, x + y)));//y倒入x中，直到x中倒满或者y倒空
		}
		return false;
	}

};