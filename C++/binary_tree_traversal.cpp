// Binary Tree Traversals by Recursion

#include<bits/stdc++.h>
using namespace std ; 

class node{
     public : 
     int data ; 
     node *left;
     node *right ; 

     node (int d){
       data =  d;
       left = NULL;
       right = NULL ; 
     }
};

// This Tree will return the address of the root node
  node* buildTree(){
       int d ; 
      cin >> d;
        if(d == -1)
        return NULL;
 
      node * root = new node(d);
        root->left = buildTree();
        root->right = buildTree();
        
        return root ; 
 }


// PreOrder Print
   void printPre(node *root){
       if(root == NULL) 
           return ; 
    // Otherwise print first root followed by subtree(children)
        cout<<root->data<<" ";
        printPre(root->left);
        printPre(root->right);   
   }


  // Inorder Print 
    void printIn(node *root){
       if(root == NULL) 
           return ; 
    // Otherwise Left Root Right
        printIn(root->left);
         cout<<root->data<<" ";
        printIn(root->right);   
   }


// Post Order Print
    void printPost(node *root){
       if(root == NULL) 
           return ; 
        // Otherwise Left Right Root
        printPost(root->left);
        printPost(root->right); 
         cout<<root->data<<" ";  
   }


// Calculating Height of binary Tree by Recursion
   int height(node *root){
     if(root == NULL)
        return 0;

        int ls = height(root->left);
        int rs = height(root->right);

        return max(ls,rs)+1;
   }
      


// Printing Kth Level Order by Recursion 
       void printKthLevel(node *root , int k){
         if(root == NULL){
           return ;
       }
        
         if(k==1){
           cout<<root->data<<" ";
           return;
         }
 
     printKthLevel(root->left,k-1);
     printKthLevel(root->right,k-1);
}

// Printing All Levels
 void printAllLevel(node *root){
     int Height = height(root);
 
   cout<<Height<<endl;
     for(int i=1; i<=Height ; i++){
       printKthLevel(root,i);
       cout<<endl;
     }    
   }



int main(){

node *root = buildTree();
  // printPre(root);
  // printIn(root) ; 
  // printPost(root);
   printAllLevel(root);
 
  
  return  0 ; 
}


/*
->3 4 -1 6 -1 -1 5 1 -1 -1 -1

PreOrder Traversal
->3 4 6 5 1

Inorder Traversal
->4 6 3 1 5

PostOrder Traversal
->6 4 1 5 3

Level Order Traversal
->8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
->8
->10 3
->1 6 14
->9 7 13



Worst Case Complexity
-> Unbalanced Binary Tree O(n^2)

*/