#include <string>
using namespace std;

//将数字转化为字符串用to_string
class Solution {
public:
	string compressString(string S) {
		if (S.size() == 0 || S.size() == 1)
		{
			return S;
		}
		string ret="";
		char last = S[0];
		ret += last;
		int cnt = 1;
		for (int i = 1; i < S.size();i++)
		{
			if (S[i]==last)
			{
				cnt++;
				continue;
			}
			ret += to_string(cnt);
			ret += S[i];
			last = S[i];
			cnt = 1;
		}
		ret += to_string(cnt);
		if (ret.size()>=S.size())
		{
			ret = S;
		}
		return ret;
	}
};