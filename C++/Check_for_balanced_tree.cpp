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

class checkBalanced
{
public:
	bool isbal;
	int height;
	checkBalanced(int height, bool isbal)
	{
		this->height = height;
		this->isbal = isbal;
	}
};

int HeightofTree(struct BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;

	return 1 + max(HeightofTree(root->left), HeightofTree(root->right));
}

checkBalanced is_balanced(struct BinaryTreeNode *root)
{
	if (root == NULL)
		return checkBalanced(0, true);
	int l = HeightofTree(root->left);
	int r = HeightofTree(root->right);
	int h = max(l, r);
	checkBalanced o(h + 1, true);
	checkBalanced left = is_balanced(root->left);
	checkBalanced right = is_balanced(root->right);
	if (!left.isbal || !right.isbal)
		o.isbal = false;
	if (abs(left.height - right.height) > 1)
		o.isbal = false;

	return o;
}

int main()
{

	struct BinaryTreeNode *root = new BinaryTreeNode(10);
	root->left = new BinaryTreeNode(20);
	root->right = new BinaryTreeNode(30);
	root->left->left = new BinaryTreeNode(10);
	root->left->right = new BinaryTreeNode(10);
	root->right->left = new BinaryTreeNode(6);
	root->right->right = new BinaryTreeNode(90);
	/*
-----------The formed tree will look like------
                      
                      10
                    /    \
                   20     30
                  /  \    /  \
                10   10  60   90
*/

	if (is_balanced(root).isbal)
		cout << "Yes, It is Balanced." << endl;
	else
		cout << "No, It is not Balanced." << endl;

	return 0;
}
