#include <vector>
using namespace std;

//����ͼ�������¹�ϵ�ͳ�����
class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> ret;
		for (int i = 0; i < num_people; i++)
		{
			ret.push_back(0);
		}
		//count��ʾ���˼���
		int count = 0;
		while (candies>0)
		{
			//����ÿ����
			for (int i = 0; i < num_people; i++)
			{
				// i+1 + num_people*count��ʾ��ǰ�����Ӧ�÷������ǡ�
				//i��ʾλ�ã���0��λ�õ��ˣ�Ҫ��1���ǣ������i+1
				//�ܹ���num_people���ˣ�ÿһ��ÿ��������Լ�����Ҫ���ϴζ෢num_people*count��
				//����ǹ���������
				int more = num_people*count;
				if (candies < i + 1 + more)
				{
					ret[i] += candies;
					candies = 0;
					break;
				}
				//�����ͼ�����
				ret[i] += i + 1 + more;
				candies -= i + 1 + more;
			}
			count++;
		}
		return ret;
	}
};