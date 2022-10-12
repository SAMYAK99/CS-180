#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;

	BinaryTreeNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

int Leftmax(struct BinaryTreeNode *root)
{
	if (root == NULL)
		return INT_MIN;
	int left = Leftmax(root->left);
	int right = Leftmax(root->right);
	return (max(max(left, right), root->data));
}

int Rightmin(struct BinaryTreeNode *root)
{
	if (root == NULL)
		return INT_MAX;
	int left = Rightmin(root->left);
	int right = Rightmin(root->right);
	return (min(min(left, right), root->data));
}

bool is_BST(struct BinaryTreeNode *root)
{
	if (root == NULL)
		return true;

	int leftmax = Leftmax(root->left);
	int rightmin = Rightmin(root->right);
	if (root->data <= leftmax || root->data > rightmin)
		return false;
	bool left = is_BST(root->left);
	bool right = is_BST(root->right);
	return left && right;
}

int main()
{

	struct BinaryTreeNode *root = new BinaryTreeNode(8);
	root->left = new BinaryTreeNode(5);
	root->right = new BinaryTreeNode(12);
	root->left->left = new BinaryTreeNode(4);
	root->left->right = new BinaryTreeNode(7);
	root->right->left = new BinaryTreeNode(11);
	root->right->right = new BinaryTreeNode(16);
	/*
-----------The formed tree will look like------
                      
                      8
                    /    \
                   5      12
                  /  \    /  \
                 4    7  11   16 
*/

	if (is_BST(root))
		cout << "Yes, It is BST." << endl;
	else
		cout << "No, It is not BST." << endl;

	return 0;
}
