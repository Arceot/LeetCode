#include <string>
using namespace std;

//视频里的方法
class Solution {
public:
	int longestPalindrome(string s) {
		int char_map[128] = { 0 };//字符哈希，数组下标对应ascii表中的字符
		int flag = 0;//是否有中心点标记
		int max_length = 0;//不算中心点时，回文数长度

		for (int i = 0; i < s.length();i++)
		{
			char_map[s[i]]++;//s[i]即表示ASCII中的字符也表示其对应的十进制数字
		}
		for (int i = 0; i < 128;i++)
		{
			if (char_map[i]%2==0)//判偶
			{
				max_length += char_map[i];
			}
			else
			{
				max_length += char_map[i] - 1;
				flag = 1;
			}
		}
		return max_length + flag;
	}
};

//我的方法 所有的偶加上奇-1,最后有奇则再加1
//其实和上面的代码一样
class Solution {
public:
	int longestPalindrome(string s) {
		int cmap[128] = {0};
		for (int i = 0; i < s.size();i++)
		{
			cmap[s[i]]++;
		}
		int maxlen = 0;
		int Odd_flag = 0;
		for (int i = 0; i < 128;i++)
		{
			if (cmap[i]%2==1)//如果未奇数，则取其偶数部分
			{
				maxlen += cmap[i] - 1;
				Odd_flag = 1;
			}
			else
			{
				maxlen += cmap[i];
			}
		}
		return maxlen + Odd_flag;//如果中间遇到过奇数，那么要加1
	}
};