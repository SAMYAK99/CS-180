#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};
int i;

int search(int *arr, int k,int begin,int n) {
    for(int i=begin;i<=n;i++) {
        if(arr[i]==k) return i;
    }
}

struct node* constructTree(int *inorder, int* preorder, int begin, int end) {
    if(begin>end) {
        return NULL;
    }
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = preorder[i];
    head->right = head->left = NULL;
    if(begin==end) {
        i++;
        return head;
    }
    int current = search(inorder,preorder[i],begin,end);
    i++;
    head->left = constructTree(inorder,preorder,begin,current-1);
    head->right = constructTree(inorder,preorder,current+1,end);
    return head;

}

void postOrder(struct node* head) {
    if(head == NULL) {
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    printf("%d ",head->data);
}

void inOrder(struct node* head) {
    if(head == NULL) {
        return;
    }
    inOrder(head->left);
    printf("%d ", head->data);
    inOrder(head->right);

}

int main() {
    int n;
    printf("Enter the no. of roots: ");
    scanf("%d", &n);
    int *inorder = (int *) calloc (n+1,sizeof(int));
    int *preorder = (int*) calloc (n+1,sizeof(int));
    for(int i=1;i<=n;i++) {
        scanf("%d", &inorder[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d", &preorder[i]);
    }

    struct node* head;
    i=1;
    head = constructTree(inorder,preorder,1,n);
    
    printf("\n");
    postOrder(head);
    printf("\n");
    inOrder(head);
    return 0;

}
