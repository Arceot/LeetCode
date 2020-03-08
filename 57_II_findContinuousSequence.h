#include <vector>
using namespace std	;
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ret;
		vector<int> vec;
		int end = target / 2 + 1;
		for (int i = 1; i <= end; i++)
		{
			vec.push_back(i);
		}
		int left = 1;
		int sum = 1;
		for (int i = 2; i <= end; i++)
		{
			sum += i;
			while (left<i-1 && sum>target)
			{
				sum -= left;
				left++;
			}
			//cout << "left=" << left << " i=" << i << " sum=" << sum << endl;
			if (sum == target)
			{
				vector<int> tmp;
				tmp.assign(vec.begin()+left-1,vec.begin()+i);
	/*			for (int j = left; j <= i; j++)
				{
					tmp.push_back(j);
				}*/
				ret.push_back(tmp);
			}
		}
		return ret;
	}
};