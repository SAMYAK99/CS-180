/* Finding if sum of any subset of the given array is equal to a given number k */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n,k;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
	cin>>arr[i];
	cin>>k;
	int f = 0;
	for(int i = 0; i < pow(2,n); i++)
	{
		int sum = 0;
		for(int j = 0; j < (log2(i)+1); j++)
		{
			if((1<<j)&i)
			sum = sum + arr[j];
		}
		if(sum == k)
		{
			f = 1;
			break;
		}
	}
	if(f)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
}
