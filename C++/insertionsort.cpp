// cpp program to implement insertion sort
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void insertion_sort(vector<ll>&arr,ll n){
    for(ll i=1;i<n;i++){
        ll key=arr[i];
        int k=i-1;
        while(k>=0 && arr[k]>key){
            arr[k+1]=arr[k];
            k--;
            arr[k+1]=key;
        }
    }
}


int main(){
    ll n;
    cout<<"HOW MANY NO DO YOU WANT TO ENTER"<<endl;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"BEFORE SORTING..."<<endl;
    for(ll x:arr){
        cout<<x<<" ";
    }

    insertion_sort(arr,n);
    cout<<endl;
    cout<<"\nAFTER SORTING..."<<endl;
    for(ll x:arr){
        cout<<x<<" ";
    }
}
