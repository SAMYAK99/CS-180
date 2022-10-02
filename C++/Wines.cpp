/* Wines Problem 
-> In one year you can sell only one bottle either extreme left or right
   Prices of all the bottles will increase ie, p[i] = p[i] * Yth year
   Find Maxm profit by selling all the bottles


-> Greedy approach of selling the lowest price bottle first will fail
   Use dp to look for the global optimum approach

    Top down Approach
      p[i] * y + f(i+1,j,y+1); 
       p[j] * y + f(j+1,i,y+1);   

  
*/

#include<bits/stdc++.h>
using namespace std ;

int  profit (int wines[] , int i , int j , int y , int dp[][100]){
  
   // base case 
    if(i>j)
      return 0 ;

   // checking if the value is already pre computed
    if(dp[i][j]!=0)
       return dp[i][j];    

   int op1 = wines[i]*y +  profit(wines,i+1,j,y+1,dp);
   int op2  = wines[j]*y + profit(wines,i,j-1,y+1,dp) ;

   return dp[i][j] =  max(op1,op2) ;   
}


int main(){
  
   int wines[] = {2,3,5,1,4} , n=5 ;
   int y = 1 ;
   int dp[100][100] = {0} ; 
  
     cout << profit(wines,0,n-1,y,dp); 

  return 0  ;
}



/*
Profit - 50


*/