// Count Binary Strings of length n which have no consective ones

#include<bits/stdc++.h>
using namespace std ;

  int f(int n){
    if(n==0)
      return 0 ;

      if(n==1)
       return 1;

      if(n==2)
       return 3 ; 

      
         return f(n-1) + f(n-2);         
  }
 


int main(){

  int  n ; 
  cin >> n;

  int ans = f(n);

  cout<<ans<<endl;


  return 0 ; 
}