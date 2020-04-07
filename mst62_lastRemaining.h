#include <vector>
#include <list>
using namespace std;
//Լɪ������
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-by-lee/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
//�е����룬û�����ף����Ĵ𰸣�����������һ����д�ü��������
class Solution {
	int f(int n, int m) {
		if (n == 1)
			return 0;
		int x = f(n - 1, m);
		return (m + x) % n;
	}
public:
	int lastRemaining(int n, int m) {
		return f(n, m);
	}
};


//���ӣ�https ://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/c-dao-tui-fa-mian-shi-ti-62-yuan-quan-zhong-zui-ho/
//����˼·
//����ʣ��һ����ʱ�İ�ȫλ�ÿ϶�Ϊ0�����ư�ȫλ��������Ϊnʱ�ı��
//����Ϊ1�� 0
//����Ϊ2��(0 + m) % 2
//����Ϊ3��((0 + m) % 2 + m) % 3
//����Ϊ4��(((0 + m) % 2 + m) % 3 + m) % 4
//........
//��������n�Ϳ��Եó���


class Solution {
public:
	int lastRemaining(int n, int m) {
		int result = 0;
		for (int i = 2; i <= n; ++i) {
			result = (result + m) % i;
		}
		return result;
	}
};

