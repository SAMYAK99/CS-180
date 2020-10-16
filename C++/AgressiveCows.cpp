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
     ll n , t= 0 , a[1000];
     cin>>n;
     REP(i,n){
         cin>>a[i];
     }

     for(int i=0;i<n;i++){
         for(int j=0;j<n-i-1;j++){
             if(a[j]<a[j+1]){
                 swap(a[j],a[j+1]); 
                  t++;
             }
               
         }
     }

      REP(i,n){
         cout<<a[i]<<" ";
     }
     //  cout<<t<<endl;
    
    return 0;
}
