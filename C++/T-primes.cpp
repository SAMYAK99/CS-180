/*  CODEFORCES LADDER DIV-2B
Codeforces Round #142 (Div 2) : T-primes
Time limit per test :2 seconds
Memory limit per test : 256 megabytes
Inputstandard : input
Outputstandard : output


We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input:
The first line contains a single positive integer, n (1 ≤ n ≤ 105), showing how many numbers are in the array. The next line contains n space-separated integers Xi (1 ≤ Xi ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.

Output:
Print n lines: the i-th line should contain "YES" (without the quotes), if number Xi is Т-prime, and "NO" (without the quotes), if it isn't.


Example:
 Sample Input
 3
 4 5 6
 Sample Output
 YES
 NO
 NO

 */

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<str> vs;
typedef vector<vector <int> > vvi;
typedef vector<vector <ll> > vvl;

const ll remi=1000000007;
const ll remi2=998244353;
const ll inf=1e18+1e17+1e16+1e15+1e14;

#define pi 3.141592653589
#define pb push_back
#define F first
#define S second
#define el "\n"
#define sp " "

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
       ll m=1000000;
	bool prime[m + 1];
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p * p <= m; p++)
	{
		if (prime[p] == true)
		{
			for (ll i = p * p; i <= m; i += p)
				prime[i] = false;
		}
	}
	prime[1]=false;
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll b;
		cin>>b;
		ll a=sqrt(b);
	if(prime[a]==true and a*a==b)
	cout<<"YES"<<el;
	else
	cout<<"NO"<<el;
	}

return 0;
}


 // Code contributed by - Deepak Verma,  Deepakv14 (Github) 

