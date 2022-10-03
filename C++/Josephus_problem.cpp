#include<bits/stdc++.h>
using namespace std;
int jos(int n,int k)
{
    if(n==1)
    return 0;
    return(jos(n-1,k)+k)%n;
}
int main()
{
    int n;
    cout<<"Enter a"<<endl;
    cin>>n;
    int k;
    cout<<"Enter k"<<endl;
    cin>>k;
    cout<<jos(n,k);
    return 0;
}
