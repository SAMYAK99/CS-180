// Aditya verma
#include<bits/stdc++.h>
#define rep(i,a,n) for( int i=a ; i<n ; i++)
#define per(i,a,n) for( int i=n-1 ; i>=a ;i--)
#define pb         push_back
#define mp         make_pair
#define vi         vector<int>
#define endl       "\n"
#define deb(x)     cerr<<#x<<" : "<<x<<"\n";
#define all(x)     x.begin(),x.end()
#define mod        1000000007
bool    compare    (int a, int b) { return b < a;}
int     gcd        (int a, int b) { return b ? gcd(b, a % b) : a;}

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

		int n , m;
		cin >> n >> m;
		int p[n];

		rep(i, 0, n)
		cin >> p[i];

		int c[m] , d[m];

		rep(i, 0, m) {
			cin >> c[i] >> d[i];
		}

		int  minutes = 0;

		if (m == 0) {
			for (int i = 0 ; i < n; i++) {
				int a = p[i];
				if (a == i + 1) {
					continue;
				}
				for (int j = 0; j < n; j++) {
					if (i == j) {
						continue;
					}
					int b = p[j];
					if (b == i + 1) {
						minutes++;
						swap(p[i], p[j]);
					}
				}
			}
			cout << minutes << endl;
		}
		else {
			//General count
			int auto_swap[n];

			rep(i, 0, n)
			auto_swap[i] = 0;

			rep(i, 0, m) {
				int a = c[i] - 1,
				    b = d[i] - 1;

				rep(j, 0, n) {
					if (j == a || j == b)
						auto_swap[j] = 1;
				}
			}
			int count = 0;
			rep(i, 0, n) {
				if (auto_swap[i]) {
					count++;
				}
			}
			//deb(count)
			// For n==5
			if (n == 5) {

				if (count == 5) {
					cout << "0\n";
				}
				if (count == 4) {

					rep(i, 0, n) {
						if (auto_swap[i] == 0) {
							if (p[i] == i + 1) {
								cout << "0\n";
							}
							else {
								cout << "1\n";
							}
						}
					}
				}
				if (count == 3) {

					int a[2], index = 0;
					rep(i, 0, n) {
						if (auto_swap[i] == 0) {
							a[index] = i;
							//deb(a[index])
							index++;
						}
					}
					if ((p[a[0]] == a[0] + 1) && (p[a[1]] == a[1] + 1)) {
						cout << "0\n";
					}
					else if ((p[a[0]] == a[1] + 1) && (p[a[1]] == a[0] + 1)) {
						cout << "1\n";
					}
					else {
						cout << "2\n";
					}
				}
				if (count == 2) {

					int a[3] = {0}, b[2] = {0}, index1 = 0, index2 = 0;
					rep(i, 0, n) {
						if (auto_swap[i] == 0) {
							a[index1] = i;
							//deb(a[index1])
							index1++;
						}
						else {
							b[index2] = i;
							//deb(b[index2])
							index2++;
						}
					}
					if ( ((p[b[0]] == b[0] + 1) && (p[b[1]] == b[1] + 1 ) ) || (((p[b[0]] == b[1] + 1) && (p[b[1]] == b[0] + 1) )) ) {

						int yes = 0;
						rep(i, 0, 3) {
							if (p[a[i]] == a[i] + 1) {
								yes++;
							}
						}
						if (yes == 3) {
							cout << "0\n";
						}
						else {
							cout << "1\n";
						}
					}
					else {
						int no_swap = 0;
						//deb(no_swap)
						rep(i, 0, 3) {
							if (p[a[i]] == a[i] + 1) {
								no_swap++;
							}
						}
						if (no_swap) {
							cout << "2\n";
						}
						else {
							cout << "3\n";
						}
					}

				}
			}
			else if (n == 4) {

				if (count == 4) {
					cout << "0\n";
				}
				else if (count == 3) {
					rep(i, 0, n) {
						if (auto_swap[i] == 0) {
							if (p[i] == i + 1) {
								cout << "0\n";
							}
							else {
								cout << "1\n";
							}
						}
					}
				}
				else {
					int a[2] = {0}, index = 0;
					rep(i, 0, n) {
						if (auto_swap[i] == 1) {
							a[index] = i;
							index++;
						}
					}
					if ( ((p[a[0]] == a[0] + 1) && (p[a[1]] == a[1] + 1)) ||  ((p[a[1]] == a[0] + 1) && (p[a[0]] == a[1] + 1)) ) {

						int b[2] = {0}, index = 0;

						rep(i, 0, 2) {
							if (auto_swap[i] == 0) {
								b[index] = i;
								index++;
							}
						}
						if ( (p[b[0]] = b[0] + 1) && (p[b[1]] = b[1] + 1) ) {
							cout << "0\n";
						}
						else {
							cout << "1\n";
						}
					}
					else {
						cout << "2\n";
					}
				}
			}
			else if (n == 3) {
				if (count == 2) {
					rep(i, 0, n) {
						if (auto_swap[i] == 0) {
							if (p[i] == i + 1) {
								cout << "0\n";
							}
							else {
								cout << "1\n";
							}
						}
					}
				}
				if (count == 3) {
					cout << "0\n";
				}
			}
			else {
				cout << "0\n";
			}
		}
	}
	return 0;
}
