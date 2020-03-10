//»¬¶¯´°¿Ú
#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int left = 0;
		int max = 0;
		for (int i = 0; i < prices.size();i++)
		{
			if (prices[i]-prices[left]>max)
			{
				max = prices[i] - prices[left];
			}
			while (left<i && prices[left]>=prices[i])
			{
				left++;
			}
		}
		return max;
	}
};