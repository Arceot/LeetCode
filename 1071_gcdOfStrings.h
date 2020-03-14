#include <string>
using namespace std;
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		string sub_str = str2;
		find_substr(str1,sub_str);
		return sub_str;
	}
	void find_substr(string str1,string& sub_str)
	{

		//可以这样判断
		//if (str1.size() == sub_str.size())
		//{
		//	for (int i = 0; i < str1.size(); i++)
		//	{
		//		if (str1[i] != sub_str[i])
		//		{
		//			sub_str="";
		//			return;
		//		}
		//	}
		//	return;
		//}

		//也可以这样判断
		if (str1+sub_str!=sub_str+str1)
		{
			sub_str = "";
			return;
		}
		if (str1.size()==sub_str.size())
		{
			return;
		}

		string long_str = str1;
		string short_str = sub_str;
		if (sub_str.size() > str1.size())
		{
			long_str = sub_str;
			short_str = str1;
		}
		int short_len = short_str.size();
		int long_len = long_str.size();
		sub_str = long_str.substr(short_len, long_len - short_len);
		find_substr(short_str, sub_str);
	}
};