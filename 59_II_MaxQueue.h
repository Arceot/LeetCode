#include <iostream>
using namespace std;
class MaxQueue {
	int v[20000];
	int begin = 0, end = 0;
public:
	MaxQueue() {
	}

	int max_value() {
		if (begin==end)
		{
			return -1;
		}
		int max = v[begin];
		for (int i = begin; i < end;i++)
		{
			if (v[i]>max)
			{
				max = v[i];
			}
		}
		return max;
	}

	void push_back(int value) {
		v[end] = value;
		end++;
	}

	int pop_front() {
		if (begin == end)
			return -1;
		int top = v[begin];
		begin++;
		return top;
	}
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/