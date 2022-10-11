// This Program will generate all the binary numbers(grey codes) of n bits and will them.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
  
	for(int i=0;i<(1<<n);i++)
	{
	    int x=i^(i>>1);
	    bitset<16>bset(x);
	    for(int i=n-1;i>=0;i--)
	    cout<<bset[i];
	    cout<<endl;
	}
	return 0;
}
