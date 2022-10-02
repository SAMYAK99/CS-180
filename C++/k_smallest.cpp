// kth smallest element in c++ 

#include <bits/stdc++.h>
using namespace std ; 

int main(){
  
     int n ; 
     cin>>n;
    
      int k;
      cin>> k ; 


     priority_queue<int> p ; 

     for(int i= 0 ;i<n;i++){
          int n  ;
          cin>>n;
          p.push(n);

          if(p.size()>k) {
            p.pop();
          }
     }

        cout<<p.top()<<endl;
    


  return 0  ;
}

/*
6
3
7 10 4 3 20 15
7
*/