#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<int> numVec;
		for (int i = 0; i < num.size();i++)
		{
			int number = num[i] - '0';
			while (numVec.size()!=0 && k>0 && number<numVec[numVec.size()-1])
			{
				numVec.pop_back();
				k--;
			}
			if (number!=0 || numVec.size()!=0)
			{
				numVec.push_back(number);
			}
		}
		while (k>0 && numVec.size()>0)
		{
			numVec.pop_back();
			k--;
		}

		string result="";
		for (int i = 0; i < numVec.size();i++)
		{
			result.append(1, numVec[i]+'0');
		}
		if (result=="")
		{
			result= "0";
		}
		return result;
	}
};