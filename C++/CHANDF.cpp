// Aditya verma
#include<bits/stdc++.h>
#define rep(i,a,n) for( int i=a ; i<n ; i++)
#define per(i,a,n) for( int i=n-1 ; i>=a ;i--)
#define pb         push_back
#define mp         make_pair
#define vi         vector<int>
#define endl       "\n"
#define int        long long int
#define deb(x)     cerr<<#x<<" : "<<x<<"\n";
#define all(x)     x.begin(),x.end()
#define mod        1000000007
bool    compare    (int a, int b) { return b < a;}
int     gcd        (int a, int b) { return b ? gcd(b, a % b) : a;}

using namespace std;

// to store the binary code of x and y
void dectobin(int a, int b , int l , int x[] , int y[] , int left[] ) {

	int index = 0;
	// Extracting the bits of X
	while (a > 0) {
		int lbit = (a & 1);
		x[index] = lbit;
		a = a >> 1;        //move the to left of binary code
		index++;
	}

	index = 0;
	//Extracting the bits of Y
	while (b > 0) {
		int lbit = (b & 1);
		y[index] = lbit;
		b = b >> 1;        //move the to left of binary code
		index++;
	}
	index = 0;
	//Extracting the bits of left of the range
	while (l > 0) {
		int lbit = (l & 1);
		left[index] = lbit;
		l = l >> 1;        //move the to left of binary code
		index++;
	}
}

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
		int x[100] = {0} ;
		int y[100] = {0} ;
		int left[100] = {0} ;

		int a, b, l, r;
		cin >> a >> b >> l >> r;
		dectobin(a, b, l, x, y, left);

		/*
		cout << "Binary of X:\n";
		for (int i = 0; i < 5; i++) {
		  cout << x[i];
		}
		cout << endl;
		cout << "Binary of Y:\n";
		for (int i = 0; i < 5; i++) {
		  cout << y[i];
		}
		cout << endl;
		cout << "Binary of L:\n";
		for (int i = 0; i < 5; i++) {
		  cout << left[i];
		}
		cout << endl;
		*/
		// now i have all binary code of x , y , left stored

		if ( (a == 0) || (b == 0) ) {
			cout << l << "\n";
		}
		else {
			int min_num = max(a, b);
			min_num = min(min_num, r);
			int init = 1 , index = 0 , ans = 0;

			//cout << min_num << endl;
			while (init <= min_num) {

				if ( (x[index] == 1) || (y[index] == 1) ) {
					ans += init;
				}

				init *= 2;
				index++;
				if (ans > r) {
					ans = ans - init / 2;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
