#include <vector>
#include <algorithm>
using namespace std;
//�������е���
//https://leetcode-cn.com/problems/trapping-rain-water-ii/
//�ǵ�����Ƶ�н����ġ��Ǹ���ά�ģ�������Ƕ�ά��Ҫ��Щ
//����ģ��ˮ�����������������ǣ������ӾͰ�ˮ���ȥ��
//�������Ӿ��ǵ�������һ����
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size()<=1)
		{
			return 0;
		}
		int max_height = 0, max_index = 0;
		for (int i = 0; i < height.size();i++)//�ҵ�������ӵ�λ��
		{
			if (height[i]>max_height)
			{
				max_height = height[i];
				max_index = i;
			}
		}
		int water_height = height[0];
		int cnt = 0;
		for (int i = 0; i <= max_index; i++)//�����������
		{
			if (height[i]<water_height)
			{
				cnt += water_height - height[i];
			}
			if (height[i]>water_height)
			{
				water_height = height[i];
			}
		}
		water_height = height.back();
		for (int i = height.size()-1; i >= max_index; i--)//���ұ�������
		{
			if (height[i]<water_height)
			{
				cnt += water_height - height[i];
			}
			if (height[i]>water_height)
			{
				water_height = height[i];
			}
		}
		return cnt;
	}
};