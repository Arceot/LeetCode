//视频链接：https://www.bilibili.com/video/av29912609?p=3

#include<iostream>
#include<cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include "120_minimumTotal.h"
using namespace std;

//struct listnode
//{
//	int val;
//	listnode* next;
//	listnode(int x) :val(x), next(NULL){}
//};
//struct treenode
//{
//	int val;
//	treenode* left;
//	treenode* right;
//	treenode(int x) :val(x), left(NULL), right(NULL) {};
//};
//struct GraphNode
//{
//	int lable;
//	vector<GraphNode*> neighbors;
//	GraphNode(int x) :lable(x){};
//};

//struct Qitem
//{
//	int x;
//	int y;
//	int h;
//	Qitem(int _x, int _y, int _h) :x(_x), y(_y), h(_h){};
//};

//struct cmp
//{
//	bool operator()(const Qitem& a, const Qitem& b)
//	{
//		return a.h > b.h;
//	}
//};


int main()
{
	Solution solve;
	//vector<int> vec1 = { 2 };
	//vector<int> vec2 = { 3,4 };
	//vector<int> vec3 = { 6,5,7 };
	//vector<int> vec4 = { 4,1,8,3 };
	vector<int> vec1 = { -1 };
	vector<int> vec2 = { 3, 2 };
	vector<int> vec3 = { -3, 1, -1 };
	vector<vector<int>> imap;
	imap.push_back(vec1);
	imap.push_back(vec2);
	imap.push_back(vec3);
	//imap.push_back(vec4);
	cout << solve.minimumTotal(imap);
	//cout << endl << solve.gcdOfStrings(str1,str2);
	//priority_queue<Qitem, vector<Qitem>, cmp> Q;
	//Q.push(Qitem(1, 2, 1));
	//Q.push(Qitem(2, 5, 0));
	//Q.push(Qitem(8, 7, 4));
	//Q.push(Qitem(6, 5, 3));
	//while (!Q.empty())
	//{
	//	cout << "x=" << Q.top().x << " y=" << Q.top().y
	//		<< " h=" << Q.top().h << endl;
	//	Q.pop();
	//}

	//vector<int> vec;
	//vec.push_back(0);
	//vec.push_back(2);
	//vec.push_back(1);
	//vec.push_back(-6);
	//vec.push_back(6);
	//vec.push_back(7);
	//vec.push_back(9);
	//vec.push_back(-1);
	//vec.push_back(2);
	//vec.push_back(0);
	//vec.push_back(1);

	//string begin_word = "a";
	//string end_word = "c";
	//string str1 = "a";
	//string str2 = "b";
	//string str3 = "c";
	//string str4 = "lot";
	//string str5 = "log";
	//string str6 = "cog";
	//vector<string> word_list;
	//word_list.push_back(str1);
	//word_list.push_back(str2);
	//word_list.push_back(str3);
	////word_list.push_back(str4);
	////word_list.push_back(str5);
	////word_list.push_back(str6);
	//cout<<endl<<solve.ladderLength(begin_word, end_word, word_list);

	/*int a = 1;
	int b = 2;
	int c = 3;
	c-=a + b;
	cout << c;

	vector<int> v1 = {2,1,1};
	vector<i,b= v2 = { 1, 1, 0 };
	vector<int> v3 = { 0, 1, 1 };
	vector<vector<int>> vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);*/
	//cout<<solve.orangesRotting(vec);
	//string str = "";
	//cout << str.length() << " " << str.size();
	//ListNode a(1);
	//ListNode b(2);
	//ListNode c(3);
	//ListNode d(4);
	//ListNode e(5);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = NULL;

	//Solution solve;
	//ListNode* head = &a;
	//while (head!=NULL)
	//{
	//	cout << head->val << endl;
	//	head = head->next;
	//}
	//cout << endl;

	//ListNode* re = solve.reverseList(&a);
	//while (re!=NULL)
	//{
	//	cout << re->val << endl;
	//	re = re->next;
	//}

	/*Solution solve;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << solve.minWindow(s, t) << endl;*/
	/*vector<string> str_vec;
	str_vec=solve.findRepeatedDnaSequences(str);
	for (int i = 0; i < str_vec.size();i++)
	{
	cout << str_vec[i] << endl;
	}*/
	/*const int table_len = 11;
	ListNode* hash_table[table_len] = {0};
	vector<ListNode*> hash_node_vec;
	int test[16] = { 1, 1, 5, 8, 66, 77, 89, 99, 122, 122, 522, 822, 662, 772, 829, 992 };
	for (int i = 0; i < 16;i++)
	{
	hash_node_vec.push_back(new ListNode(test[i]));
	}
	for (int i = 0; i < hash_node_vec.size();i++)
	{
	insert(hash_table, hash_node_vec[i], table_len);
	}
	printf("hash table\n");
	for (int i = 0; i < table_len; i++)
	{
	printf("[%d]:", i);
	ListNode* head=hash_table[i];
	while (head)
	{
	printf("%d->", head->val);
	head = head->next;
	}
	printf("NULL\n");
	}
	for (int i = 0; i < 1000;i++)
	{
	if (search(hash_table, i, table_len))
	{
	printf("%d is in hash table\n",i);
	}
	}
	for (int i = 0; i < hash_node_vec.size();i++)
	{
	delete hash_node_vec[i];
	}*/



	/*int random[10] = { 999, 1, 9, 55, 777, 444, 33, 9, 7, 9 };
	int num_map[1000] = {0};
	for (int i = 0; i < 10;i++)
	{
	num_map[random[i]]++;
	}
	for (int i = 0; i < 1000;i++)
	{
	for (int count = 0; count < num_map[i];count++)
	{
	printf("%d\n",i);
	}
	}*/
	/*string str = "qwqqrfvbghnggggg";
	int char_map[128] = {0};
	for (int i = 0; i < str.length();i++)
	{
	char_map[str[i]]++;
	}
	for (int i = 0; i < 128;i++)
	{
	if (char_map[i]>0)
	{
	printf("[%c] [%d]:%d\n",i,i, char_map[i]);
	}
	}*/
	/*TreeNode root(8);
	int test[] = { 3, 10, 1, 6, 15 };
	vector<TreeNode*> node_vec;
	for (int i = 0; i < 5;i++)
	{
	node_vec.push_back(new TreeNode(test[i]));
	}
	for (int i = 0; i < node_vec.size();i++)
	{
	BST_insert(&root, node_vec[i]);
	}
	print_tree_node(&root,0);
	Codec codec;
	string str=codec.serialize(&root);
	cout << str<<endl;
	TreeNode* reRoot = codec.deserialize(str);
	print_tree_node(reRoot, 0);


	for (int i = 0; i < node_vec.size();i++)
	{
	delete node_vec[i];
	}*/
	//for (int i = 4; i < 8; i++)
	//{
	//	vec.push_back(i);
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	vec.push_back(i);
	//}
	//vec.push_back(1);
	//vec.push_back(3);
	//Solution solve;
	//cout<<solve.search(vec, 2);

	//const int MAX_N = 5;
	//GraphNode* graph[MAX_N];
	//for (int i = 0; i < MAX_N; i++)
	//{
	//	graph[i] = new GraphNode(i);
	//}
	//graph[0]->neighbors.push_back(graph[4]);
	//graph[0]->neighbors.push_back(graph[2]);
	//graph[1]->neighbors.push_back(graph[0]);
	//graph[1]->neighbors.push_back(graph[2]);
	//graph[2]->neighbors.push_back(graph[3]);
	//graph[3]->neighbors.push_back(graph[4]);
	//graph[4]->neighbors.push_back(graph[3]);
	//int visit[MAX_N] = { 0 };
	//for (int i = 0; i < MAX_N; i++)
	//{
	//	if (visit[i] == 0)
	//	{
	//		cout << "From label[" << graph[i]->lable << "]:";
	//		//DFS_graph(graph[i], visit);
	//		BFS_graph(graph[i], visit);
	//		cout << endl;
	//	}
	//}
	//for (int i = 0; i < MAX_N; i++)
	//{
	//	delete graph[i];
	//}
	//TreeNode a(3);
	//TreeNode b(5);
	//TreeNode c(1);
	//TreeNode d(6);
	//TreeNode e(2);
	//TreeNode f(0);
	//TreeNode g(8);
	//TreeNode h(7);
	//TreeNode i(4);
	//a.left = &b;
	//a.right = &c;
	//b.left = &d;
	//b.right = &e;
	//c.left = &f;
	//c.right = &g;
	//e.left = &h;
	////e.right = &i;
	//Solution solve;
	//print_tree_node(&a,0);
	//vector<int> vec=solve.rightSideView(&a);
	//for (int i = 0; i < vec.size();i++)
	//{
	//	cout << vec[i];
	//}
	//queue<TreeNode*> trQueue;
	//trQueue.push(&a);
	//while (!trQueue.empty())
	//{
	//	cout << trQueue.front()->val<<endl;
	//	if (trQueue.front()->left != NULL)
	//	{
	//		trQueue.push(trQueue.front()->left);
	//	}
	//	if (trQueue.front()->right != NULL)
	//	{
	//		trQueue.push(trQueue.front()->right);
	//	}
	//	trQueue.pop();
	//}


	//vector<int> vec1;
	//vec1.push_back(10);
	//vec1.push_back(60);
	//Solution solve;
	//solve.countSmaller(vec1);
	/*ListNode a(3);
	ListNode b(2);
	ListNode c(0);
	ListNode d(-4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;*/


	/*vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(60);

	vector<int> vec2;
	vec2.push_back(20);
	vec2.push_back(30);

	vector<int> vec3;
	vec3.push_back(30);
	vec3.push_back(30);

	vector<int> vec4;
	vec4.push_back(60);
	vec4.push_back(40);

	vector<vector<int>> vecVec;
	vecVec.push_back(vec1);
	vecVec.push_back(vec2);
	vecVec.push_back(vec3);
	vecVec.push_back(vec4);*/

	//cout << points[0][0] << " "
	//	<< points[0][1] << " "
	//	<< points[1][0] << " "
	//	<< points[1][1] << " "
	//	<< points[2][0] << " "
	//	<< points[2][1] << " "
	//	<< points[3][0] << " "
	//	<< points[3][1] << endl;

	//cout << solve.minRefuelStops(100,10,vecVec) << endl;

	//solve.canJump();
	//ListNode* head = solve.detectCycle(&a);
	//cout << head->val<< endl;

	//vector<int> numsJump;
	//for (int i = 0; i < 10; i++)
	//{
	//	numsJump.push_back(1);
	//	cout << numsJump[i];
	//}

	system("pause");
	return 0;
}
//void print_tree_node(TreeNode* treenode, int layer)
//{
//	if (treenode == NULL)
//	{
//		return;
//	}
//	for (int i = 0; i < layer; i++)
//	{
//		cout << "----";
//	}
//	cout << "[" << treenode->val << "]" << endl;
//	print_tree_node(treenode->left, layer + 1);
//	print_tree_node(treenode->right, layer + 1);
//}

////深度优先搜索
//void DFS_graph(GraphNode* node, int* visit)
//{
//	visit[node->lable] = 1;
//	cout << node->lable << " ";
//	for (int i = 0; i < node->neighbors.size(); i++)
//	{
//		if (visit[node->neighbors[i]->lable] == 0)
//		{
//			DFS_graph(node->neighbors[i], visit);
//		}
//	}
//}
//
////广度优先搜索 自己想的
//void BFS_graph(GraphNode* node, int* visit)
//{
//	if (visit[node->lable] == 0)
//	{
//		cout << node->lable << " ";
//		visit[node->lable] = 1;
//	}
//	for (int i = 0; i < node->neighbors.size(); i++)//先把下一层的都遍历完
//	{
//		if (visit[node->neighbors[i]->lable] == 0)
//		{
//			cout << node->neighbors[i]->lable << " ";
//			//visit[node->neighbors[i]->lable] = 1;//这里先不置1，为什么？
//		}
//	}
//	for (int i = 0; i < node->neighbors.size(); i++)//再继续向下一层遍历
//	{
//		if (visit[node->neighbors[i]->lable] == 0)
//		{
//			visit[node->neighbors[i]->lable] = 1;//到这里再置1，为什么？
//			BFS_graph(node->neighbors[i], visit);
//		}
//	}
//}
//
////广度优先搜索 自己想的 修改待试验
//void BFS_graph(GraphNode* node, int* visit)
//{
//	//if (visit[node->lable] == 0)
//	//{
//	//	cout << node->lable << " ";
//	//	visit[node->lable] = 1;
//	//}
//	for (int i = 0; i < node->neighbors.size(); i++)//先把下一层的都遍历完
//	{
//		if (visit[node->neighbors[i]->lable] == 0)
//		{
//			cout << node->neighbors[i]->lable << " ";
//			visit[node->neighbors[i]->lable] = 1;//这里先不置1，为什么？
//		}
//	}
//	for (int i = 0; i < node->neighbors.size(); i++)
//	{
//		BFS_graph(node->neighbors[i], visit);
//	}
//}
//
//
////视频里的
//void BFS_graph(GraphNode* node, int* visit)
//{
//	queue<GraphNode*> Q;
//	Q.push(node);
//	visit[Q.front()->lable] = 1;
//	while (!Q.empty())
//	{
//		cout << Q.front()->lable << " ";
//		//visit[Q.front()->lable] = 1;//这里置1太晚了，2在3前面，3还没置1时，2又访问了一遍3；这里输出的顺序是0 4 2 3
//		for (int i = 0; i < Q.front()->neighbors.size(); i++)
//		{
//			if (visit[Q.front()->neighbors[i]->lable] == 0)
//			{
//				Q.push(Q.front()->neighbors[i]);
//				visit[Q.front()->neighbors[i]->lable] = 1;//push进去之后置1
//			}
//		}
//		Q.pop();
//	}
//
//}
//
//void BST_insert(TreeNode* root,TreeNode* insert_node)
//{
//	if (insert_node->val<root->val)
//	{
//		if (root->left==NULL)
//		{
//			root->left = insert_node;
//		}
//		else
//		{
//			BST_insert(root->left, insert_node);
//		}
//	}
//	else
//	{
//		if (root->right==NULL)
//		{
//			root->right = insert_node;
//		}
//		else
//		{
//			BST_insert(root->right, insert_node);
//		}
//	}
//}
//
//int hash_func(int key, int table_len)
//{
//	return key%table_len;
//}
//void insert(ListNode* hash_table[],ListNode* node,int table_len)
//{
//	int hash_key = hash_func(node->val, table_len);
//	node->next = hash_table[hash_key];//使用头插法插入节点
//	hash_table[hash_key] = node;
//}
//bool search(ListNode* hash_table[],int val,int table_len)
//{
//	int val_key = val%table_len;
//	ListNode* head=hash_table[val_key];
//	while (head)
//	{
//		if (head->val==val)
//		{
//			return true;
//		}
//		head = head->next;
//	}
//	return false;
//}