#include <string>
using namespace std;

//�Լ�д���߼�̫���ӣ������ǲο��ı���д��
//�ص�����һ��һ�εڽ����жϣ����ʼ��ȥ�������Ŀո�
//Ȼ���ж�������
//ʣ�µľ�ֻ�������ֿ�ͷ����Ϊ����������ʱ���ŷ������⡣
//��Ҫע����ǣ��ж��������
class Solution {
public:
	int myAtoi(string str) {
		int sign_flag = 1;
		int i = 0;
		int ret = 0;
		while (str[i]==' ')//�Ƚ�ǰ��Ŀո�ȥ��
		{
			i++;
			continue;
		}
		if (str[i]=='-')//����
		{
			sign_flag = -1;
		}
		if (str[i]=='+' || sign_flag==-1)//����
		{
			i++;
		}
		while (i<str.size())
		{
			int num = str[i] - '0';
			if (num>9 || num<0)//�����������ֵ��ַ�
			{
				break;
			}
			if (INT_MAX/10<ret || (INT_MAX/10==ret && num>7))//ͨ��/������*�ж����
			{
				return sign_flag == -1 ? INT_MIN : INT_MAX;
			}
			ret = ret * 10 + num;//�������д��ret = ret * 10 + str[i]-'0'���жϣ���ô�ȼ������ret*10+str[i]�ᵼ�����
			i++;
		}
		return sign_flag == 1 ? ret : -ret;
	}
};