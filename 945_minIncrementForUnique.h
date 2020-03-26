#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minIncrementForUnique(vector<int>& A) {
		sort(A.begin(), A.end());//��С��������
		int cnt = 0;
		for (int i = 1; i < A.size();i++)
		{
			if (A[i]<=A[i-1])//�����һ����ǰһ��С���ͽ���һ����Ϊ��ǰһ����1����
			{
				cnt +=A[i-1]-A[i]+1 ;
				A[i] = A[i - 1]+1;
			}
		}
		return cnt;
	}
};
//class Solution {
//public:
//	int minIncrementForUnique(vector<int>& A) {
//		unordered_set<int> mset;
//		vector<int> repeat_vec;
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (mset.count(A[i])==0)//û�ظ�
//			{
//				mset.insert(A[i]);
//			}
//			else//�ظ���
//			{
//				repeat_vec.push_back(A[i]);
//			}
//		}
//		int cnt = 0;
//		sort(repeat_vec.begin(), repeat_vec.end());
//		for (int i = 0; i < repeat_vec.size();i++)
//		{
//			while (mset.count(repeat_vec[i])!=0)
//			{
//				repeat_vec[i]++;
//				cnt++;
//			}
//			mset.insert(repeat_vec[i]);
//		}
//		return cnt;
//	}
//};