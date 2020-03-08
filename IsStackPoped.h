#include<vector>
#include<stack>
using namespace std;
class IsStackPoped {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int n = popped.size();
		stack<int> temp_stack;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			temp_stack.push(pushed[i]);
			while (!temp_stack.empty()&&popped[j]==temp_stack.top())
			{
				temp_stack.pop();
				j++;
			}
		}
		if (!temp_stack.empty())
		{
			return false;
		}
		else
		{
			return true;
		}

	}
};