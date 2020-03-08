#include <string>
using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		string ret(n-1,'a');
		if (n%2==1)//ÆæÊı
		{
			ret += 'a';
		}
		else
		{
			ret += 'b';
		}
		return ret;
	}
};