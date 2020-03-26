#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		sort(arr.begin(),arr.end());
		vector<int> ret;
		ret.assign(arr.begin(), arr.begin()+k);
		return ret;
	}
};