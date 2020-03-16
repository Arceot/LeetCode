#include <vector>
using namespace std;
class CustomStack {
public:
	CustomStack(int maxSize) {
		maxlen = maxSize;
		for (int i = 0; i < maxlen;i++)
		{
			vec.push_back(0);
		}
	}

	void push(int x) {
		if (right<maxlen)
		{
			vec[right] = x;
			right++;
		}
	}

	int pop() {
		if (right>0)
		{
			right--;
			return vec[right];
		}
		return -1;
	}

	void increment(int k, int val) {
		int len = right;
		if (k<right)
		{
			len = k;
		}
		for (int i = 0; i < len;i++)
		{
			vec[i] += val;
		}
	}
private:
	vector<int> vec;
	int maxlen;
	int right = 0;
};

/**
* Your CustomStack object will be instantiated and called as such:
* CustomStack* obj = new CustomStack(maxSize);
* obj->push(x);
* int param_2 = obj->pop();
* obj->increment(k,val);
*/