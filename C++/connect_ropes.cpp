// Connect ropes 
// Join all the ropes 
// cost of all the ropes is define by joing two ropes at a time

// Intution - At any time always take 2 ropes with minimum cost [Optimal]
//  basically utilising the property of HEAPIFY


#include<bits/stdc++.h>
using namespace std ;

int main(){
    
    int  n , sum = 0 ; 
     priority_queue<int , vector<int> ,greater<int>>  mheap  ; 

     cin>> n ; 
      int ropes[n];


     for(int i = 0 ; i<n ;i++){
            cin>>ropes[i]; 
             mheap.push(ropes[i]);
     }

    
      while (mheap.size() > 1 )
      {
           
         int first = mheap.top();
           mheap.pop();
           int second = mheap.top();
           mheap.pop();
           int csum = first + second ; 
                sum += csum  ;
              mheap.push(csum);     
      }

        cout<<sum<<endl;
      
}

/*
5
1 2 3 4 5

33
*/