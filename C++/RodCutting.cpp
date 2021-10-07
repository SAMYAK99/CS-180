/*
Rod Cutting Problem
-> Find the maximum profit for cutting of a rod of length n


*/


#include<bits/stdc++.h>
using namespace std ;


// Recursive Solution
int maxProfitRec(int prices[] ,int n){
 int maxProfit = INT_MIN;

 // base case
   if(n<=0)
    return 0 ;

  //Recursive Case
  for(int i=0 ;i<n ;i++){
    int cutRod = i+1;
    int curPrice = prices[i] + maxProfitRec(prices , n-cutRod);
    maxProfit = max(maxProfit,curPrice);
  }  
  return maxProfit ;
}



// Bottom UP DP Solution
int maxProfitDp(int prices[] , int n){
 
   int dp[n+1] ;
   dp[0] = 0 ; 


   for(int len=1 ; len<= n ; len++){
     int ans = INT_MIN;

     for(int i=0 ;i<len ;i++){
       int cut = i+1 ;
       int curPrice = prices[i] + dp[len-cut] ;
       ans = max(ans ,curPrice) ;
     }
     dp[len] = ans ;
   }  

  return dp[n] ; 
}


int main(){

 int prices[] = {1,5,8,9,10,17,17,20} ;
 int n = sizeof(prices)/sizeof(int) ;

 int ans = maxProfitDp(prices,n);

  cout << ans << endl ;


  return 0 ;
}

/*
Output - 22 

*/