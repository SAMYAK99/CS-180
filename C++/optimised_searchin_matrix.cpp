#include <iostream>
using namespace std;

int main()
 {
     int m,n;
     cin>>m>>n;
     int a[m][n];

     for(int i=0; i<m; i++)
     {
         for(int j=0; j<n; j++)
         {
             cin>>a[i][j];
         }
     }
    int target, r=0, c=n-1;
    cin>> target;
     while(r<m && c>=0)
     {
         if(a[r][c]==target)
         {
             cout<<"no. found at " << r <<"," << c;
             return 0;
         }
         else if (a[r][c]<target)
         {
             r++;
         }
         else 
         {
             c--;
         }
     }

     cout<< "no. not found";
     return 0;
 }