#include <iostream>
using namespace std;

// Making the Tree node
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL; // initializing the left , right pointer node by default null
    }
};

bool BST_Search(node*root,int key){
    // Base condition for recursion , this means we have travelled whole tree but key not found.
    if(root==NULL)
    return false;
    
    // When key found
    if(root->data==key)
    return true;
    
    // When key is less than the parent node value
    else if(root->data<key)
    return BST_Search(root->right,key);
    
    // When key is greater than parent node value
    else
    return BST_Search(root->left,key);
    
    return false;
}
int main() {
	node*root=new node(3);
	root->left=new node(2);
	root->right=new node(5);
	root->left->left=new node(1);
	root->left->right=new node(3);
	root->right->left=new node(4);
	root->right->right=new node(6);
	
	int key=4;
	
	if(BST_Search(root,key))
	cout<<"Key "<<key<<" Found in Binary Search Tree";
	
	else
	cout<<"Key"<<key<<"Not Found in Binary Search Tree";
	return 0;
}
