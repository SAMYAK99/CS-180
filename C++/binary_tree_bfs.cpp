// Binary Tree bfs traversal

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



// bfs Traversal
   void bfs(node *root){
       queue< node* > q ;
     
     q.push(root);
     q.push(NULL);

     while (!q.empty()){
       node* f = q.front();
  
    // for new line charachter
        if(f==NULL){
           cout<<endl;
           q.pop();
           if(!q.empty()){
             q.push(NULL);
           }          
       }

        else{
       cout<<f->data<<",";
       q.pop() ; 
     

      if(f->left){
        q.push(f->left);
      }

       if(f->right){
        q.push(f->right);
      }
     }
    }
     
     return ; 
   
   }


int main(){

node *root = buildTree();
  
    bfs(root);

  return  0 ; 
}


/*
->3 4 -1 6 -1 -1 5 1 -1 -1 -1

BFS Traversal 
 Complexity - O(n)
->8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
->8
->10 3
->1 6 14
->9 7 13



*/