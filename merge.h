//LeetCode 面试题 10.01
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode-cn.com/problems/sorted-merge-lcci/solution/tu-jie-shuang-zhi-zhen-yuan-di-xiu-gai-by-z1m/
//原地的算法
class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		if (m==0)
		{
			for (int i = 0; i<n;i++)
			{
				A[i] = B[i];
			}
		}
		while (i>=0 && j>=0)
		{
			if (A[i]>=B[j])
			{
				A[k] = A[i];
				i--;
			}
			else
			{
				A[k] = B[j];
				j--;
			}
			k--;
		}
		while (i>=0)
		{
			A[k] = A[i];
			k--;
			i--;
		}
		while (j >= 0)
		{
			A[k] = B[j];
			k--;
			j--;
		}
	}
};

//class Solution {
//public:
//	void merge(vector<int>& A, int m, vector<int>& B, int n) {
//		for (int i = m; i < m + n;i++)
//		{
//			A[i] = B[i - m];
//		}
//		sort(A.begin(), A.end());
//	}
//};


//class Solution {
//public:
//	void merge(vector<int>& A, int m, vector<int>& B, int n) {
//		int i = 0, j = 0;
//		vector<int> vec;
//		while (i < m && j < n)
//		{
//			if (A[i] <= B[j])
//			{
//				vec.push_back(A[i]);
//				i++;
//			}
//			else
//			{
//				vec.push_back(B[j]);
//				j++;
//			}
//		}
//		while (i < m)
//		{
//			vec.push_back(A[i]);
//			i++;
//		}
//		while (j < n)
//		{
//			vec.push_back(B[j]);
//			j++;
//		}
//		for (int i = 0; i < m + n; i++)
//		{
//			A[i] = vec[i];
//		}
//	}
//};