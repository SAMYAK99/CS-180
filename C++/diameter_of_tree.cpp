// Diameter of a Binary Tree is the number of nodes on the longest path between two leaves in a tree
// There can be 3 cases --- 
// diameter is maxm in left subtree  = call h1
//  paases from root   = h1 + h2 
// passes from right subtree  = call h2

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
      

//  Diameter of Binary Tree by preorder traversal
// Complexity - O(n^2)
// top to bottom approach
  int diameter (node *root){
    if(root == NULL)
      return 0  ;

      int h1 = height(root->left);
      int h2 = height(root->right);
     
      int op1 = h1 + h2 ;
       int op2 = diameter(root->left);
       int op3  = diameter(root->right);

       return max(op1,max(op2,op3));

  }

  //  Diameter of Binary Tree = OPTIMIZED by PostOrder Traversal
  // Complexity - O(n)
  // bottom up approach 
  
    pair<int, int> fastDiameter(node* root){
	       pair<int, int> p;

	      if(root == NULL){
	        	p.first = 0;
	        	p.second = 0;

		     return p;
   	}

	pair<int, int> left_child = fastDiameter(root->left);
  pair<int, int> right_child = fastDiameter(root->right);
     p.first = max(left_child.first, right_child.first) + 1;  //height
     p.second = max((left_child.first + right_child.first) ,max(left_child.second, right_child.second)); //diameter
    
    return p;
}
    


int main(){

node *root = buildTree();
 cout << diameter(root);
	cout <<"\n";
	pair<int, int> p = fastDiameter(root);
	cout<<"height= "<<p.first<<" "<<"diameter= "<<p.second;

  return  0 ; 
}


/*
->3 4 -1 6 -1 -1 5 1 -1 -1 -1

->Diameter is = 4

*/