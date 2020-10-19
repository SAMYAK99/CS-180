// Aditya verma
#include<bits/stdc++.h>
#define rep(i,a,n) for( int i=a ; i<n ; i++)
#define per(i,a,n) for( int i=n-1 ; i>=a ;i--)
#define pb         push_back
#define mp         make_pair
#define vi         vector<int>
#define endl       '\n'
#define int        long long int
#define deb(x)     cerr<<#x<<" : "<<x<<"\n";
#define all(x)     x.begin(),x.end()
#define mod        1000000007
bool    compare    (int a, int b) {return a < b;}
int     gcd        (int a, int b) {return b ? gcd(b, a % b) : a;}

using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n , k ;
		cin >> n >> k;
		int a[n] , b[n];

		rep(i, 0, n) {
			cin >> a[i];
		}
		rep(i, 0, n) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		int index = 0;
		per(i, 0, n) {
			if (k == 0) break;
			if (a[index] > b[i]) break;
			a[index] = b[i];
			index++;
			k--;
		}
		int sum = 0;
		rep(i, 0, n) {
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
