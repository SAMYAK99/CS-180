// sort k sorted array OR nearly sorted array 

//  the value present in the array could be place +- k distance from its current index 


#include <bits/stdc++.h>
using namespace std ; 

int main(){
  
     int n ; 
     cin>>n;
    
      int k;
      cin>> k ; 


     priority_queue<int , vector<int> , greater<int>> min_heap ; 
       vector<int> v;

     for(int i= 0 ;i<n*k;i++){
          int n  ;
          cin>>n;
          min_heap.push(n); 

            if(min_heap.size() > k){
               v.push_back(min_heap.top());     // these elements are already sorted in array 
                 min_heap.pop();
            }    
     }

     for(int i=0 ; i< v.size() ; i++ )
         cout<<v[i]<<" ";                    // printing the sorted array
 
         while(min_heap.size()>0){
       cout<<min_heap.top()<<" ";           // printing the remaining elements of the array 
         min_heap.pop();
     }
   

  return 0  ;
}

/*
6
3
7 10 4 3 20 15
3 4 7 10 15 20
*/