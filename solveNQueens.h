#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> location;//������Q��...���лʺ��λ����Q
		vector<vector<int>> mark;//��СΪ���̣��ʺ󼰻ʺ�Ĺ�����Χ���Ϊ1
		
		//��ʼ��location��mark
		string s(n, '.');
		vector<int> loc(n,0);
		for (int i = 0; i < n;i++)
		{
			location.push_back(s);
			mark.push_back(loc);
		}

		generate(0, n, location, mark, result);
		return result;
	}

private:

	//k:ÿ�����ҽ���1���ʺ����ڷ��õ�k�еĻʺ�k��0��ʼ
	//n:n�У���n������
	void generate(int k, int n,vector<string>& location,
		vector<vector<int>>& mark, vector<vector<string>>& result)
	{
		if (k==n)//��k=nʱ��������������лʺ�ķ��ã�����¼�ʺ�λ�õĶ�ά����location��push��result��
		{
			result.push_back(location);
			return;
		}
		for (int i = 0; i < n;i++)//��˳���Ե�0����n�У�ע���ǡ��С�
		{
			if (mark[k][i]==0)//������Է��ûʺ�
			{
				vector<vector<int>> tem_mark = mark;//��¼����ǰ��mark����
				put_down_the_queen(k, i, mark);//���ûʺ�
				location[k][i] = 'Q';//��¼��ǰ�ʺ��λ��

				generate(k + 1, n, location, mark, result);//�ݹ���һ�з���

				mark = tem_mark;//��mark��ֵΪ����ǰ��״̬��
				location[k][i] = '.';//����ǰ���Ե�λ�����¸�ֵΪ��.��
			}
		}
	}

	//�ڣ�x,y������������mark[��][��]��ʾ����
	void put_down_the_queen(int x,int y,vector<vector<int>>& mark)
	{
		mark[x][y] = 1;//�ڣ�x,y����������
		//�������飬�˸����򡣷���һ�����������Χ�˸�����������ٷ�������
		static const int dx[] = {-1,-1,-1,0,0,1,1,1};
		static const int dy[] = {-1,0,1,-1,1,-1,0,1};
		for (int i = 1; i < mark.size();i++)//ÿ��������������1�����N-1
		{
			for (int j = 0; j < 8;j++)//�˸�����
			{
				int new_x = x + dx[j] * i;//dx,dy�������������Ϊ������б�ʵĶ���
				int new_y = y + dy[j] * i;
				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())//�߽�
				{
					mark[new_x][new_y] = 1;
				}
			}
		}
	}

};