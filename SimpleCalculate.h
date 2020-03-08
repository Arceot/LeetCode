#include<string>
#include<stack>
using namespace std;

class SimpleCalculate {
public:
	int calculate(string s) {
		static const int BEGIN_STATE = 0;
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		int STATE = BEGIN_STATE;
		stack<int> number_stack;
		stack<char> operation_stack;
		int number = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i]==' ')
			{
				continue;
			}
			switch (STATE)
			{
			case BEGIN_STATE:
				if (s[i]>='0'&& s[i]<='9')
				{
					STATE = NUMBER_STATE;
				}
				else
				{
					STATE = OPERATION_STATE;
				}
				i--;
				break;
			case NUMBER_STATE:
				if (s[i] >= '0'&& s[i] <= '9')
				{
					number = number * 10 + s[i] - '0';
				}
				else
				{
					number_stack.push(number);
					compulte(number_stack,operation_stack);
					STATE = OPERATION_STATE;
					i--;
				}
				break;
			case OPERATION_STATE:
				if (s[i]=='+' || s[i]=='-')
				{
					operation_stack.push(s[i]);
					STATE = NUMBER_STATE;
					i--;
				}
				else if (s[i]=='(')
				{
					
				}

				break;

			}
		}

	}
	int compulte(stack<int> &numStack,stack<char> &operStack)
	{
	
	}
};