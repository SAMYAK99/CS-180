#include<bits/stdc++.h>
using namespace std;

void move(int n , char source , char helper , char dest) {

	//base case
	if (n == 0)
		return;

	//recursive case
	//moving n-1 disk from source to helper
	move(n - 1, source, dest, helper);
	cout << "Shift disk " << n << " from " << source << " to " << dest << endl;

	//now move the n-1 disk present on helper to dest
	move(n - 1 , helper , source , dest);
}

int main() {

	int n; cin >> n;
	move(n, 'A', 'B', 'C');

	return 0;
}