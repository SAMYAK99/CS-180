// k largest elements in array 

#include <bits/stdc++.h>
using namespace std ; 

int main(){
  
     int n ; 
     cin>>n;
    
      int k;
      cin>> k ; 


     priority_queue<int , vector<int> , greater<int>> min_heap ; 

     for(int i= 0 ;i<n;i++){
          int n  ;
          cin>>n;
          min_heap.push(n); 

            if(min_heap.size() > 3){
               min_heap.pop();
            }    
     }


      while(min_heap.size()>0){
       cout<<min_heap.top()<<" ";
         min_heap.pop();
     }


  return 0  ;
}

/*
6
3
7 10 4 3 20 15
10 15 20
*/