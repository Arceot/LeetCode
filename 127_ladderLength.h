#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

//��һ���ٶȿ죬���ұ���,Ҳ�ǿ���
//https://leetcode-cn.com/problems/word-ladder/solution/cpp-yi-ge-si-lu-de-zhuan-bian-cong-1156msjia-su-da/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> iset;
		for (auto& i:wordList) iset.insert(i);
		queue<pair<string, int>> Q;
		Q.push(make_pair(beginWord, 1));
		while (!Q.empty())
		{
			string node = Q.front().first;
			int step = Q.front().second;
			Q.pop();
			if (node==endWord) return step;
			//��node��ÿ����ĸ���ó����������26����ĸ�����滻����set�в���
			//�ҵ��˾ͼ�������У�����set��ɾ��
			for (int i = 0; i < node.size();i++)
			{
				char tmp = node[i];
				for (char c = 'a'; c <= 'z';c++)
				{
					node[i] = c;
					if (iset.find(node)!=iset.end())
					{
						Q.push(make_pair(node, step + 1));
						iset.erase(node);
					}
				}
				//��node[i]��ԭ��ȥ
				node[i] = tmp;
			}

		}
		return 0;
	}
};

////˫��Ŀ��ѣ���begin_word��end_wordͬʱ��������,���һ����������û�г�ʱ���������
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		map<string, vector<string>> graph;
//		creat_graph(beginWord, wordList, graph);
//		return BFS_graph(beginWord, endWord, graph);
//	}
//private:
//	void creat_graph(string beginWord, vector<string>& wordList, map<string, vector<string>>& graph)
//	{
//		//�ж�begin�ڲ���wordlist��
//		int flag = 0;
//		for (int i = 0; i < wordList.size();i++)
//		{
//			if (wordList[i]==beginWord)
//			{
//				flag = 1;
//			}
//		}
//		//���ھͷŽ�ȥ
//		if (flag==0)
//		{
//			wordList.push_back(beginWord);
//		}
//		for (int i = 0; i < wordList.size(); i++)
//		{
//			for (int j = i + 1; j < wordList.size(); j++)
//			{
//				if (can_link(wordList[i], wordList[j]))
//				{
//					graph[wordList[i]].push_back(wordList[j]);
//					graph[wordList[j]].push_back(wordList[i]);
//				}
//			}
//		}
//	}
//
//	bool can_link(string word1, string word2)
//	{
//		int cnt = 0;
//		for (int i = 0; i < word1.size(); i++)
//		{
//			if (word1[i] != word2[i])
//			{
//				cnt++;
//			}
//		}
//		return cnt == 1;
//	}
//	int BFS_graph(string beginWord, string endWord, map<string, vector<string>>& graph)
//	{
//		queue<pair<string, int>> left_Q;
//		map<string,int> left_visit;
//		left_Q.push(make_pair(beginWord, 1));
//		left_visit[beginWord]=1;
//
//		queue<pair<string, int>> right_Q;
//		map<string, int> right_visit;
//		right_Q.push(make_pair(endWord, 1));
//		right_visit[endWord]=1;
//
//		while (!left_Q.empty() && !right_Q.empty())
//		{
//			if (left_Q.size() <= right_Q.size())//�Ӷ����ٵ���һ�˿�ʼ����
//			{
//				if (right_visit.find(left_Q.front().first)!=right_visit.end())
//				{
//					return left_visit[left_Q.front().first] + right_visit[left_Q.front().first]-1;
//				}
//				visit_neighbors(graph, left_visit, left_Q);
//			}
//			else
//			{
//				if (left_visit.find(right_Q.front().first) != left_visit.end())
//				{
//					return left_visit[right_Q.front().first] + right_visit[right_Q.front().first]-1;
//				}
//				visit_neighbors(graph, right_visit, right_Q);
//			}
//		}
//		return 0;
//	}
//
//	void visit_neighbors(map<string, vector<string>>& graph,
//		map<string,int>& visit, queue<pair<string, int>>& Q)
//	{
//		string node = Q.front().first;
//		int step = Q.front().second;
//		Q.pop();
//
//		vector<string>& neighbors = graph[node];
//
//		for (int i = 0; i < neighbors.size(); i++)
//		{
//			if (visit.find(neighbors[i]) == visit.end())
//			{
//				Q.push(make_pair(neighbors[i], step + 1));
//				visit[neighbors[i]] = step + 1;
//			}
//		}
//	}
//};


//��Ƶ��ķ�����map����ͼ�����õ���Ŀ���
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		map<string, vector<string>> graph;
//		creat_graph(beginWord,wordList,graph);
//		return BFS_graph(beginWord,endWord,graph);
//	}
//private:
//	void creat_graph(string beginWord,vector<string>& wordList, map<string, vector<string>>& graph)
//	{
//		for (int i = 0; i < wordList.size();i++)
//		{
//			if (can_link(beginWord, wordList[i]))
//			{
//				graph[beginWord].push_back(wordList[i]);
//			}
//
//			for (int j = i + 1; j<wordList.size();j++)
//			{
//				if (can_link(wordList[i],wordList[j]))
//				{
//					graph[wordList[i]].push_back(wordList[j]);
//					graph[wordList[j]].push_back(wordList[i]);
//				}
//			}
//		}
//	}
//
//	bool can_link(string word1,string word2)
//	{
//		int cnt = 0;
//		for (int i = 0; i < word1.size();i++)
//		{
//			if (word1[i]!=word2[i])
//			{
//				cnt++;
//			}
//		}
//		return cnt == 1;
//	}
//	int BFS_graph(string beginWord,string endWord,map<string,vector<string>>& graph)
//	{
//		queue<pair<string, int>> Q;//int���ڼ�¼�ڼ���
//		set<string> visit;//��¼��������Щ��
//		Q.push(make_pair(beginWord,1));//��������ʵĵ�
//		visit.insert(beginWord);
//		while (!Q.empty())
//		{
//			//����ͷ���ĵ�
//			string node = Q.front().first;
//			int step = Q.front().second;
//			Q.pop();
//			if (node==endWord)
//			{
//				return step;
//			}
//			//�����ڵĵ����
//			const vector<string>& neighbors = graph[node];
//			for (int i = 0; i < neighbors.size();i++)
//			{
//				if (visit.find(neighbors[i])==visit.end())
//				{
//					Q.push(make_pair(neighbors[i], step+1));//������step++�������⣬++step����
//					visit.insert(neighbors[i]);
//				}
//			}
//		}
//		return 0;
//	}
//};