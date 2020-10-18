//C++ program to demonstrate deletion operation in binary search tree
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

//A utility function to create a new BST node
struct node *newNode(int item){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

//A utility function to do inorder traversal
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

//A utility function to insert a new node with given key in BST
struct node* insert(struct node* root, int data){
    //if the tree is empty return a new node.
    if(root == NULL){
        return newNode(data);
    }
    //otherwise recur down the tree
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    //return the(unchanged) node pointer.
    return root;
}
/*given a non empty binary search tree ,return the node with
minimum data value in that tree.Note that the entire tree
does not need to be searched. */
struct node* minValueNode(struct node* root){
    struct node* current = root;
    //loop down to find the leftmost leaf.
    while (current && current->left != NULL)
    {
        current=current->left;
    }
    return current;   
}

/*given a binary search tree and a key,this function deletes
the key and return the new root*/

struct node* deleteNode(struct node* root,int data){
    //base case
    if(root==NULL){
        return root;
    }
    //if the key to be deleted is smaller than root's key
    //then it lies in the left subtree.
    if(data<root->data){
        root->left=deleteNode(root->left,data);
    }
    //if the key to be deleted is smaller than root's key
    //then it lies in the right subtree.
    else if(data>root->data){
        root->right=deleteNode(root->right,data);
    }
    //if the key to be deleted is same as root's key
    //then this is the node to be deleted.
    else{
        //node with only one child or no child.
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }

        //node with two children:ge the inorder successor
        //(smallest in the rigth sub tree).
        struct node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
    /*let us create following BST
             50
           /    \
          30    70
         /  \   / \
        20  40 60 80   */
    struct node *root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);

    cout<<"Inorder traversal"<<endl;
    inorder(root);

    cout<<"\nDelete 20\n"<<endl;
    root=deleteNode(root,20);

    cout<<"BST after deleting 20"<<endl;
    inorder(root);

    cout<<"\nDelete 30\n"<<endl;
    root=deleteNode(root,30);

    cout<<"BST after deleting 30"<<endl;
    inorder(root);

    cout<<"\nDelete 50\n"<<endl;
    root=deleteNode(root,50);

    cout<<"BST after deleting 50"<<endl;
    inorder(root);
}