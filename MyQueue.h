#include<stack>
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		std::stack<int> temp_stack;
		while (!_data_stack.empty())
		{
			temp_stack.push(_data_stack.top());
			_data_stack.pop();
		}
		_data_stack.push(x);
		while (!temp_stack.empty())
		{
			_data_stack.push(temp_stack.top());
			temp_stack.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int x = _data_stack.top();
		_data_stack.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		return _data_stack.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _data_stack.empty();
	}
private:
	std::stack<int> _data_stack;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/