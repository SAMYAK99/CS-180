// C++ program for flattening a Linked List

#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node *right, *down;
};
 
Node* head = NULL;
Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }
 
    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
 
Node* flatten(Node* root)
{
    if (root == NULL || root->right == NULL)
        return root;
 
    root->right = flatten(root->right);
    root = merge(root, root->right);
    return root;
}

Node* push(Node* head_ref, int data)
{
    Node* new_node = new Node();
 
    new_node->data = data;
    new_node->right = NULL;
    new_node->down = head_ref;

    head_ref = new_node;
 
    return head_ref;
}
 
void printList()
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}
 
// Driver's code
int main()
{
 
    /* created the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);
 
    head->right = push(head->right, 20);
    head->right = push(head->right, 10);
 
    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);
 
    head->right->right->right
        = push(head->right->right->right, 45);
    head->right->right->right
        = push(head->right->right->right, 40);
    head->right->right->right
        = push(head->right->right->right, 35);
    head->right->right->right
        = push(head->right->right->right, 20);
 
    head = flatten(head);
 
    printList();
    return 0;
}
 
