#include<iostream>
using namespace std;



int main() {
     int n,m ; 
     cin>>m>>n;

     int arr[4][4];

     for(int i=0;i<m;i++){
            for(int j = 0 ;j<n;j++)
             cin>>arr[i][j];
     }
     int sum =  0 ; 
   //col wise search
    for(int i=m-1;i>=0;i--){
            for(int j =n-2 ;j>=0;j--)
             arr[i][j] += arr[i][j+1];
     }

     //row wise search
      for(int i=m-1;i>=0;i--){
            for(int j = n-2 ;j>=0;j--)
             arr[j][i] +=arr[j+1][i];
     }

     //max sum
      for(int i=0;i<n;i++){
            for(int j = 0 ;j<m;j++)
             sum = max(sum, arr[i][j]);
     }

     cout<<sum;
   return 0 ;
}