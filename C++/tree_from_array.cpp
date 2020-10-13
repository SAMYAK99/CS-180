/*
Replace every Node by sum of its child  (all descendants) node (don't change the leaves nodes)
*/

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

node* buildTreeFromArray (int *a ,int s , int e){
   
    //Base Case
   if(s>e)
    return NULL ;

     int mid = (s+e)/2 ; 
     node *root = new node(mid);
     root->left = buildTreeFromArray(a,s,mid-1);
     root->right = buildTreeFromArray(a,mid+1,e);

    return root ; 
 }

// bfs Print
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

  int arr[ ] = {1,2,3,4,5,6,7};
  int s = 0 ; 
  int e = 6 ;

node *root = buildTreeFromArray(arr , s, e);
   bfs(root) ; 

  return  0 ; 
}


/*
3,
1,5,
0,2,4,6,

*/