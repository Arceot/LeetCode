#include <vector>
using namespace std;

//看别人的，正面讨论重叠的情况
class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec1[0]<rec2[2] && rec1[1]<rec2[3]//1的左下小于2的右上
			&& rec2[0]<rec1[2] && rec2[1]<rec1[3])//且2的左下小于1的右上
		{
			return true;
		}
		return false;
	}
};