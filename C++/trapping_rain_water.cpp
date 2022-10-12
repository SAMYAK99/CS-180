#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long arr[n],larr[n],rarr[n];
	    long twater=0,lm=-1,rm=-1;
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	        if(arr[i]>lm)
	        lm = arr[i];
	        larr[i] = lm;
	    }
	    for(int i=n-1; i>=0; i--)
	    {
	        if(arr[i]>rm)
	        rm = arr[i];
	        rarr[i] = rm;
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        twater+=min(larr[i],rarr[i])-arr[i];
	    }
	    cout<<twater<<'\n';
	}
	return 0;
}
