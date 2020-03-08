#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	string rankTeams(vector<string>& votes) {
		map<string, vector<int>> imap;
		for (int i = 0; i < votes.size();i++)
		{
			for (int j = 0; j < votes[j].size();j++)
			{
				imap[votes[j]][j]++;
			}
		}
		string result;
		for (int i = 0; i < ; i++)
		{

		}

	}
};