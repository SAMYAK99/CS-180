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
 
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
 
int main()
{
    struct Node* root = newNode(5);
    root->left = newNode(9);
    root->right = newNode(0);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
 
    return 0;
}
