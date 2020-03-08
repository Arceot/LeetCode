#include <string>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
	// Encodes a tree to a single string.
	//����ת��Ϊ�ַ���
	string serialize(TreeNode* root) {
		string data;
		BST_preorder(root,data);//ǰ�������
		return data;
	}

	// Decodes your encoded data to tree.
	//���ַ���ת��Ϊ��
	TreeNode* deserialize(string data) {
		if (data.length()==0)//�п�
		{
			return NULL;
		}
		vector<TreeNode*> valVec;
		int val = 0;
		for (int i = 0; i < data.length();i++)
		{
			if (data[i]=='#')//������push��vector
			{
				valVec.push_back(new TreeNode(val));
				val = 0;
			}
			else//���ַ���ת��Ϊ���֣�����һ���������
			{
				val =val*10+ data[i] - '0';
			}
		}
		//��vector�е���ֵ�����������
		for (int i = 1; i < valVec.size();i++)
		{
			BST_insert(valVec[0], valVec[i]);
		}
		return valVec[0];
	}
private:

	//ǰ�����������ת��Ϊ�ַ���
	void BST_preorder(TreeNode* node,string& data)
	{
		if (node==NULL)
		{
			return;
		}
		string str_val;
		change_into_string(node->val,str_val);//����ֵת��Ϊ�ַ���
		data += str_val;
		BST_preorder(node->left, data);
		BST_preorder(node->right, data);
	}

	//������ת��Ϊ�ַ���������β�����ϡ�#��
	void change_into_string(int val,string& str_val)
	{
		string tmp;
		while (val)//���ֲ�һ���Ǹ�λ�������ܵ������ֺܳ�
		{
			tmp += val % 10 + '0';
			val = val / 10;
		}
		for (int i = tmp.length()-1; i>=0;i--)
		{
			str_val += tmp[i];
		}
		str_val += '#';
	}

	//�����ֲ�������
	void BST_insert(TreeNode* node, TreeNode* insertNode)
	{
		if (insertNode->val<node->val)//�����
		{
			if (node->left==NULL)
			{
				node->left =insertNode;
			}
			else
			{
				BST_insert(node->left, insertNode);
			}
		}
		else//���ұ�
		{
			if (node->right==NULL)
			{
				node->right =insertNode;
			}
			else
			{
				BST_insert(node->right, insertNode);
			}
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));���Եĵ���˳��