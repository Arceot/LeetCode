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
			//std::unordered_set �ǻ���hashʵ�ֵġ�
			//std::set �ǻ��ں����ʵ�ֵġ�
			size_t key = (size_t)x * 100000007 + y;
			if (iset.find(key) != iset.end())//���֮ǰ���ʹ��˾��˳�
			{
				continue;
			}
			iset.insert(key);
			/********/

			if (x==z||y==z||x+y==z)
			{
				return true;
			}
			
			Q.push(make_pair(full_x, y));//x����
			Q.push(make_pair(0, y));//x����
			Q.push(make_pair(x + y - min(full_y, x + y), min(full_y, x + y)));//x����y�У�ֱ��y�е�������x����

			Q.push(make_pair(x, full_y));//y����
			Q.push(make_pair(x, 0));//y����
			Q.push(make_pair(min(full_x, x + y), x + y - min(full_x, x + y)));//y����x�У�ֱ��x�е�������y����
		}
		return false;
	}

};