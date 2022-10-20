#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        reverse(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}

// T.C = O(n)
// S.C = O(n)
