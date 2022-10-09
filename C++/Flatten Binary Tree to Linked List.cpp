// Program to Flatten given binary tree to linked list


#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

class Solve 
{
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(10);
  root -> left = newNode(20);
  root -> left -> left = newNode(30);
  root -> left -> right = newNode(40);
  root -> right = newNode(50);
  root -> right -> right = newNode(60);
  root -> right -> right -> left = newNode(70);

  Solve obj;

  obj.flatten(root);
  while(root->right!=NULL)
  {
      cout<<root->data<<"->";
      root=root->right;
  }
cout<<root->data;
  return 0;
}

//Output:

//10->20->30->40->50->60->70

//Time Complexity: O(N)

//Space Complexity: O(N)
