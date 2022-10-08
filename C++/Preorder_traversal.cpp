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
    struct Node* root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(9);
    root->left->right = newNode(0);
 
 
      // Function call
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
 
    return 0;
}
