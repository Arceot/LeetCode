#include <vector>
#include <list>
using namespace std;
//约瑟夫环问题
//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-by-lee/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//有点难想，没想明白，抄的答案，，，后面有一个人写得简单容易理解
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


//链接：https ://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/c-dao-tui-fa-mian-shi-ti-62-yuan-quan-zhong-zui-ho/
//解题思路
//最终剩下一个人时的安全位置肯定为0，反推安全位置在人数为n时的编号
//人数为1： 0
//人数为2：(0 + m) % 2
//人数为3：((0 + m) % 2 + m) % 3
//人数为4：(((0 + m) % 2 + m) % 3 + m) % 4
//........
//迭代推理到n就可以得出答案


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

