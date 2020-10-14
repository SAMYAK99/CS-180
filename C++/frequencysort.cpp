// Frequency Sort
//  --Approach-- 
//  Store the frequency of each element in the map 
// sort the map with frequency 

#include <bits/stdc++.h>
using namespace std ; 

int main(){
  
     int  n ;
    
    unordered_map<int,int> mp ; 
     priority_queue< pair<int,int>>  mheap  ;
    

      cin>> n ; 
     int arr[n];

       for(int i= 0 ;i<n ;i++){
            cin >> arr[i];
       }
        
  // Counting the frequency of each element
      for(int i = 0 ;i <n ;i++){
            mp[arr[i]]++;
       } 

 
     // pushing the map in the heap 

       for(auto it = mp.begin() ; it!=mp.end() ; it++ ) {
          
            mheap.push(make_pair(it->second,it->first));
                   
       }


       while (mheap.size()>0){
             int freq = mheap.top().first;
              int element = mheap.top().second;

               for(int i = 0  ;i <freq ; i++)
                 cout<<element<<" ";

           mheap.pop();
            
       }
   
  return 0  ;
}

/*
7
1 1 1 3 2 2 4

1 1 1 2 2 4 3
*/