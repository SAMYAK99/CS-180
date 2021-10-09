#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include<bits/stdc++.h>
using namespace std;

#ifdef pranat_sharma1    
    #include "debugger.cpp"
#endif

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define float               long double
#define F                   first
#define S                   second
#define pb                  push_back
#define mp                  make_pair
#define mod                 1000000007
#define endl                "\n"

bool isPowerOfTwo(int n)
{
   return n && (!(n&(n-1)));
}

void solve()
{
        
    if(isPowerOfTwo(4))
        cout << "YES\n";
    else
        cout << "NO\n";

}   

int32_t main()
{

    fastIO
    cout << setprecision(15) << fixed;

    int t = 1;
    // cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": \n";
        solve();
    }

    return 0;

}