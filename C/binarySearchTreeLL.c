#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) 
    return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main()
{
    int op,srchno,n;
  struct node *root = NULL;
  for(;;)
{   
    printf("\n1. Insert\t2. Delete\t3. inorder Traversal\t4. EXIT\nEnter what you want :\t");
    printf("\n Enter your choice\n");
    scanf("%d",&op);
  switch (op)
   {
    case 1: printf("\n Enter the element to insert\n");
              scanf("%d",&n);
              root=insert(root,n);
              break;
    case 2: printf("\n Enter the element to be deleted\n");
              scanf("%d",&srchno);
              root = deleteNode(root, srchno);
              break;
    case 3: printf("\n The inorder tree traversal is\n");
              inorder(root);
              break;
    case 4: exit(1);
    default: printf("\ninvalid choice!\n");
   }
  }
  return 0;
}