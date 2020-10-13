#include <bits/stdc++.h>
using namespace std; 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
typedef unsigned long long int ll;

void seive(ll *p){

      
     for(ll i=3;i<1000005;i+=2)
      p[i]=1;
      
     for(ll i=3;i<1000005;i+=2){
          if(p[i]==1){
              for(ll j=i*i;j<1000005;j=j+i)
                p[j]=0;
          }
      }
      p[0]=p[1]=0;
      p[2]=1;
      
}



int main()
{
    ll p[1000005];
     seive(p);
       ll csum[1000005] = {0};
        for(ll i=1 ;i<1000005;i++)
           csum[i] = csum[i-1] + p[i];
     
    
      ll t;
      cin>>t;
      
      while(t--){
     ll a,b;
    cin>>a>>b;
    
      cout<<csum[b]-csum[a-1]<<endl;
    

      }     
    return 0;
}