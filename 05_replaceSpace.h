#include <string>
using namespace std;

//����һ��string ret������s����s[i]����ret�У�
//��s[i]=�ո�ʱ����%20����ret�У�
//����ret
class Solution {
public:
	string replaceSpace(string s) {
		string ret = "";
		for (int i = 0; i < s.size();i++)
		{
			if (s[i]==' ')
			{
				ret += "%20";
				continue;
			}
			ret += s[i];
		}
		return ret;
	}
};
