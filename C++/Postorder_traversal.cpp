#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
 
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(4);
    root->left->left = newNode(11);
    root->left->right = newNode(5);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
 
    return 0;
}
