#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int num = 0;
		int min = light[0];
		int max = light[0];
		//kʱ�̴�light[k]�����,light[k]�ǵƵ�λ��
		for (int k = 0; k < light.size();k++)
		{
			if (light[k]<min)
			{
				min = light[k];
			}
			if (light[k]>max)
			{
				max = light[k];
			}
			//������һ�ο��Բ�Ҫ��Ҫ�Ļ���һЩ
			//kʱ�̴���k+1���ƣ�
			//�������Ǵ򿪵Ƶ�λ������Ǵ���k+1
			//��ô�϶��������
			//if (light[k]>k+1)
			//{
			//	continue;
			//}
			if (min == 1 && max == k + 1)
			{
				//cout << light[k] << " ";
				num++;
			}
		}
		return num;
	}
};