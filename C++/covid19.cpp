// Aditya verma
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define per(i,a,n) for(int i=n-1 ; i>=a ;i--)
#define pb         push_back
#define mp         make_pair
#define int        long long int
#define vi         vector<int>
#define endl       '\n'
#define deb(x)     cerr<<#x<<" : "<<x<<"\n";
#define all(x)     x.begin(),x.end()
#define mod        1000000007
bool    compare    (int a, int b) {return b < a;}
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
		int n , q;
		cin >> n >> q;
		string s;
		cin >> s;
		int freq[26] = {0};
		rep(i, 0, n) {
			char current = s.at(i);
			freq[current - 97]++;
		}
		rep(i, 0, q) {
			int c;
			cin >> c;
			int res = 0;
			rep(i, 0, 26) {
				if (freq[i] > c)
					res += (freq[i] - c );
			}
			cout << res << endl;
		}
	}
	return 0;
}