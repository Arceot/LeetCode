#include <vector>
using namespace std;

//�����˵ģ����������ص������
class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec1[0]<rec2[2] && rec1[1]<rec2[3]//1������С��2������
			&& rec2[0]<rec1[2] && rec2[1]<rec1[3])//��2������С��1������
		{
			return true;
		}
		return false;
	}
};