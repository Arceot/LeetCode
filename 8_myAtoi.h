#include <string>
using namespace std;

//自己写的逻辑太复杂，这里是参考的别人写的
//重点在于一段一段第进行判断，如最开始先去掉连续的空格
//然后判断正负号
//剩下的就只有以数字开头并且为连续的数字时，才符合题意。
//需要注意的是，判断溢出那里
class Solution {
public:
	int myAtoi(string str) {
		int sign_flag = 1;
		int i = 0;
		int ret = 0;
		while (str[i]==' ')//先将前面的空格去掉
		{
			i++;
			continue;
		}
		if (str[i]=='-')//负号
		{
			sign_flag = -1;
		}
		if (str[i]=='+' || sign_flag==-1)//正号
		{
			i++;
		}
		while (i<str.size())
		{
			int num = str[i] - '0';
			if (num>9 || num<0)//遇到不是数字的字符
			{
				break;
			}
			if (INT_MAX/10<ret || (INT_MAX/10==ret && num>7))//通过/而不是*判断溢出
			{
				return sign_flag == -1 ? INT_MIN : INT_MAX;
			}
			ret = ret * 10 + num;//这里如果写成ret = ret * 10 + str[i]-'0'来判断，那么先计算的是ret*10+str[i]会导致溢出
			i++;
		}
		return sign_flag == 1 ? ret : -ret;
	}
};