#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> vec;
		for (int i = 0; i < coins.size();i++)
		{
			vec.push_back(coins[i]);
		}
		sort(vec.begin(), vec.end());
		int cnt = 0;
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			while (amount >= vec[i])
			{
				amount -= vec[i];
				cnt++;
				cout << "cnt=" << cnt << " amount=" << amount 
					<< " vec[" << i << "]=" << vec[i] << endl;
			}
		}
		if (amount!=0)
		{
			return -1;
		}
		return cnt;
	}
};