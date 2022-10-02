//Aditya verma
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
		int n , k;
		cin >> n >> k;
		int p[n + 1] , ans = k;

		int indices[n + 1];

		rep(i, 1, n + 1) {
			cin >> p[i];
			indices[p[i]] = i;
		}
		vi steps , pairs ;

		rep(i, 1, n + 1) {
			//deb(i)
			if (p[i] == i) {
				continue;
			}
			else {
				int b_index = i, index_b = indices[i], a_index = index_b, index_a = indices[a_index];

				//deb(a_index)
				//deb(b_index)
				//found a pair
				if (i == index_a) {
					//cerr << "found a pair \n";
					pairs.pb(a_index);
					pairs.pb(b_index);
					//swapping
					p[index_a] = b_index;
					p[index_b] = a_index;
				}
				else {
					int c_index = p[b_index];
					p[b_index] = b_index, indices[i] = i, p[indices[a_index]] = c_index,
					                                   indices[c_index] = index_a, p[index_b] = a_index, indices[a_index] = index_b;
					/*cout << "new arr\n";
					rep(i, 1, n + 1) {
					  cout << p[i] << " ";
					}
					cout << endl;*/
					steps.pb(b_index);
					steps.pb(index_a);
					steps.pb(index_b);
					k--;
				}
			}
		}
		if (pairs.size() % 4 == 0 && k >= 0) {
			int nextline = 0;
			cout << pairs.size() / 2 - k + ans << endl;
			rep(i, 0, steps.size()) {
				nextline++;
				cout << steps.at(i) << " ";
				if (nextline % 3 == 0) {
					nextline = 0;
					cout << endl;
				}
			}
			nextline = 0;
			for (int i = 0; i < pairs.size(); i += 4) {
				cout << indices[pairs.at(i)] << " "
				     << indices[pairs.at(i + 2)] << " "
				     << indices[pairs.at(i + 3)] << " " << endl;
				cout << indices[pairs.at(i + 2)] << " "
				     << indices[pairs.at(i + 1)] << " "
				     << indices[pairs.at(i)] << " " << endl;
			}
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}
