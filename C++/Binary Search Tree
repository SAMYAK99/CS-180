#include<bits/stdc++.h>
using namespace std;
struct bst
{
    long data;
    struct bst* left;
    struct bst* right;
};
bst* root = nullptr;
struct bst* insert(struct bst* n,long val)
{
    if(n == NULL)
    {
        struct bst* f = new bst();
        f->data = val;
        f->left = f->right = NULL;
        return f;
    }
    else
    {
        if(val <= n->data)
        n->left = insert(n->left, val);
        else
        n->right = insert(n->right, val);
    }
}
void pre(struct bst* n)
{
    if(n == NULL)
    return;
    printf("%ld\n",n->data);
    pre(n->left);
    pre(n->right);
}
struct bst* search(struct bst* temp, long q)
{
    if(temp == NULL)
    return NULL;
    if(temp->data == q)
    return temp;
    else if(temp->data >= q)
    search(temp->left, q);
    else
    search(temp->right, q);
}
int main()
{
    int n;
    cin>>n;
    long kk;
    cin>>kk;
    root = new bst();
    root->data = kk;
    root->left = root->right = NULL;
    for(int i = 1; i < n; i++)
    {
        long a;
        cin>>a;
        insert(root,a);
    }
    long q;
    cin>>q;
    //struct bst* f = search(root, q);
    pre(root);
}
