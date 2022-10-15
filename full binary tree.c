#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node 
{
        int item;
        struct Node * left, * right;
};

struct Node * createNewNode(char k) 
{
        struct Node * node = (struct Node * ) malloc(sizeof(struct Node));
        node -> item = k;
        node -> right = node -> left = NULL;
        return node;
}

bool isFullBinaryTree(struct Node * root) 
{
        // Checking tree emptiness
        if (root == NULL)
                return true;

        // Checking the presence of children
        if (root -> left == NULL && root -> right == NULL)
                return true;

        if ((root -> left) && (root -> right))
                return (isFullBinaryTree(root -> left) && isFullBinaryTree(root -> right));

        return false;
}

int main() 
{
        struct Node * root = NULL;
        root = createNewNode(1);
        root -> left = createNewNode(2);
        root -> right = createNewNode(3);

        root -> left -> left = createNewNode(4);
        root -> left -> right = createNewNode(5);
        root -> left -> right -> left = createNewNode(6);
        root -> left -> right -> right = createNewNode(7);

        if (isFullBinaryTree(root))
                printf("The tree is full binary tree\n");
        else
                printf("The tree is not full binary tree\n");
}
