#include <string>
using namespace std;
class Solution {
public:
	int numSteps(string s) {
		int cnt = 0;
		while (s != "1")
		{
			//cout << "s=" << s << endl;
			if (s[s.size() - 1] == '0')//ż��
			{
				//cout << "ż��" << endl;
				cnt++;
				s=s.assign(s.begin(), s.end()-1);//��2
				continue;
			}
			if (s[s.size() - 1] == '1')//����
			{
				//cout << "����" << endl;
				cnt++;
				for (int i = s.size() - 1; i >= 0;i--)
				{
					if (s[i]=='1')
					{
						s[i] = '0';//ע���д��0��
						if (i == 0)
						{
							s = "1" + s;
							break;
						}
						continue;
					}
					if (s[i]=='0')
					{
						s[i] = '1';
						break;
					}
				}
			}
		}
		return cnt;
	}
};
