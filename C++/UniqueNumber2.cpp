// Unique Numbers 2 
#include <bits/stdc++.h>
using namespace std; 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
int main()
{  
      int    xo  = 0 ,  res  , a[100005]  , pos = 0 ; 
      int n ; 
      cin>>n;

      // finding xor of each numbers
      REP(i,n){
          cin>>a[i];
          res  = xo ^a[i];
      }
        int temp = res ;

        // finding a particular set bit
        while ((temp &1) != 1)
        {
            pos++;
            temp >> 1 ; 
        }
        
        // creating mask of set bit
        int mask = 1<<pos ; 

        //finding the numbers which have the same set bit
        int x = 0 , y=  0 ;  
        REP(i,n){
            if((a[i] &mask) > 0 )
              x^=a[i];
             
        }
         y = x ^ res  ;
         cout<<min(x,y)<<" "<<max(x,y)<<endl;
    
    return 0;
}