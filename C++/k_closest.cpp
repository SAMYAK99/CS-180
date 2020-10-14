// Find a set of numbers which are closest to the given number k
// Approach
// -> Take absolute difference and store all in the pair with the corresponding element 
// ->  Sort then print it in max heap

#include <bits/stdc++.h>
using namespace std ; 

int main(){
  

     int n ; 
     cin>>n;
    

     priority_queue<pair<int,int>> p_heap ; 

       int arr[n];

       for(int i= 0 ;i <n ;i++)
         cin>>arr[i];

     int k;
      cin>> k ; 

       int no;
       cin>>no ; 

      


     for(int i= 0 ;i<n;i++){
          int idx = abs(arr[i]-no);
          p_heap.push(make_pair(idx,arr[i])); 

            if(p_heap.size() > k){
                 p_heap.pop();
            }    
     }

       while (p_heap.size() > 0)
       {
           cout<<p_heap.top().second<<" ";
             p_heap.pop();
       }
          

  return 0  ;
}

/*
5
5 6 7 8 9
3                  // no. of elements 
7
8 6 7             // nearest to 7
*/