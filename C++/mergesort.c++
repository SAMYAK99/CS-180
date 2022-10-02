#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(int *v,int s,int m,int e)
{
	int t[e-s+1];
	int i=s;
	int j=m+1;int k=0;
	while(i<=m && j<=e)
	{
		if(v[i]<=v[j])
		{
			t[k]=v[i];
			k++;i++;
		}
		else
		{
			t[k]=v[j];
			k++;j++;
		}
	}

	while(i<=m)
	{
		t[k]=v[i];
		k++;i++;
	}
	while (j<=e)
	{
		t[k]=v[j];
			k++;j++;
	}

	for(int i=0;i<=((sizeof(v))-1);i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void msort(int *v,int s,int e)
{
	if(s<e)
	{
		int m=(s+e)/2;
		msort(v,s,m);
		msort(v,m+1,e);
		merge(v,s,m,e);
	}
}

int main()
{
	int n;
	cout<<"enter n;";
	cin>>n;
	int v[n];
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	msort(v,0,n);
}
