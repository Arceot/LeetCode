#include <vector>
#include <algorithm>
using namespace std;

//ת��
//�����У���ÿ�����ߵĵ�Ի���
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n==0)
		{
			return;
		}
		//ת�ã���������������Ϊ�Խ�����ת��
		for (int i = 0; i < n;i++)
		{
			for (int j = i; j < n;j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
		//����
		int mid = n / 2;
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < mid;j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = tmp;
			}
		}
	}
};