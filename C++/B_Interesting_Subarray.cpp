// take the subarray with two elements that are contiguous and check whether the absolute difference between them is greater than or equal to 2 

#include <bits/stdc++.h>
using namespace std; 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long int  ll;
int main()
{
      ll t ;
      cin>>t;
      
      while(t--){
          ll n ;
          cin>>n;

          ll a[n];
          REP(i,n)
            cin>>a[i];

          ll left=0 , right = 0 , flag = 0 ;

        for(ll i=0 ;i<n-1;i++){
             if(abs(a[i+1]-a[i])>=2){
                  left =i+1;
                  right =i+2;
                  flag =1;
                  break;
             }
        }

         if(!flag)
          cout<<"NO\n";
          else
           cout<<"YES\n"<<left<<" "<<right<<endl;
      }
      

    return 0;
 }