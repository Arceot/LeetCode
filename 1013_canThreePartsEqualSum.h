#include <vector>
using namespace std;
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		if (A.size()<3)
		{
			return false;
		}
		int sum = 0;
		for (int i = 0; i < A.size();i++)
		{
			sum += A[i];
		}
		if (sum%3)
		{
			return false;
		}
		int target = sum / 3;
		int cnt = 0;
		int sub_sum = 0;
		for (int i = 0; i < A.size();i++)
		{
			sub_sum += A[i];
			if (sub_sum==target)
			{
				sub_sum = 0;
				cnt++;
			}
		}
		//Ӧ����>=3������==3,���統targetΪ0ʱ��
		//��ô��������Էֳ�4��targetʱҲ���Ժϲ�Ϊ����target
		if (cnt>=3)
		{
			return true;
		}
		return false;
	}
};


//�����и�С����Ҫ����£������˵�
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		if (A.size() < 3)
		{
			return false;
		}
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			sum += A[i];
		}
		if (sum % 3)
		{
			return false;
		}
		int target = sum / 3;
		int cnt = 0;
		int sub_sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			sub_sum += A[i];
			if (sub_sum == target)
			{
				sub_sum = 0;
				cnt++;
				//���������ҵ�3��target�󣬺���ĺͿ϶�Ϊ0�ˣ�
				//Ҳ�Ϳ��Ժϲ���ǰ���target����
				if (cnt == 3)
				{
					return true;
				}
			}
		}
		return false;
	}
};