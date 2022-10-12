#include<bits/stdc++.h>
using namespace std;

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define mod                 1000000007

// Binary Exponentiation/ Fast Exponentiation
int power(int a , int n)
{
    // for calculating a^n in O(logn)
    int res = 1;

    while(n)
    {
        if(n&1)
        {
            res = res * a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}

void solve()
{
           
    cout << power(2, 5) << endl;   

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