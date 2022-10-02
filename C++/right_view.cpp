// Right View of The Tree
// DFS -- Traversing Right to Left
// root -> right -> left              
// If a new level is encountered print the first element of that level  



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



// Printing right View of the tree

void printRightView( node*root , int level, int &max_level ){

    if(root == NULL)
       return  ;

      if(max_level < level){
        // We have encountered a new level 
         cout<<root->data<<" ";
         max_level = level ; 
      } 

      // right
      // left
         printRightView(root->right, level+1 , max_level );
         printRightView(root->left , level+1 , max_level) ; 

}


int main(){

node *root = buildTree();
   
   
   int mx_level = -1 ;
   printRightView(root , 0 , mx_level) ;

  return  0 ; 
}


/*
-> 3 4 -1 6 -1 -1 5 1 -1 -1 -1
-> 3 5 1
*/