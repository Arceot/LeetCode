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
		//应该用>=3而不是==3,比如当target为0时，
		//那么当数组可以分成4份target时也可以合并为三分target
		if (cnt>=3)
		{
			return true;
		}
		return false;
	}
};


//这里有个小点需要体会下，看别人的
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
				//体会这里，当找到3个target后，后面的和肯定为0了，
				//也就可以合并到前面的target里了
				if (cnt == 3)
				{
					return true;
				}
			}
		}
		return false;
	}
};