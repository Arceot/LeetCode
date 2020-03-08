#include <string>
using namespace std;

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