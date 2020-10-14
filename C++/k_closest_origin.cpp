// K closest point to origin  , pair of 2 points are given
// --Approach--
// Calculate distance from origin x^2+y^2
// sort this distance and store it in max heap 
// dispaly 


#include<bits/stdc++.h>
using namespace std ;
int main(){

  int k=2;
  int n;

   pair<int,pair<int,int>> p ; 
   priority_queue<pair<int,pair<int,int>>> mheap ; 

   cin>>n;

   // storing the cordinates in pair 
   // x^2+y^2    1st element    2nd elment

   for(int i=0 ; i<n ;i++){
       int x,y ;
       cin >> x >> y ;
       int dist = x*x + y*y  ;
        mheap.push(make_pair(dist,make_pair(x,y)));

         if(mheap.size()>k)
           mheap.pop();
   } 


   while (mheap.size()>0){
       pair<int,int> pi = mheap.top().second  ;
        cout<<pi.first<<" "<<pi.second<<endl;
         mheap.pop();
   }
   


return 0  ;
}

/*
4
1 3
-2 2
5 8
0 1


-2 2
0 1
*/