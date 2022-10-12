#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
Bucket sort is a sorting algorithm which sorts data in a specific range and is uniformly distributed in linear time.

If we take the number of buckets as n or n/2 or n/3 then the time requirred for insertion,sorting,joining of buckets take linear time.

This algorithm will work very badly if the data is not uniformly dist this algorithm works very badly.

Assuming n approx = k / when we have perfectly distributed data :

Time complexity : O(n) (when we have constant elements in each bucket sorting the elements takes const time and concat is also O(n) operation)

Worst case : when the elements are not uniformly dist and all elements end up in one bucket. So if we use insertion sort we get O(n^2). 
But if we use some other algo to sort the buckets we get O(nlogn)

*/
void bucket_sort(int arr[],int n,int k){
    int range=*max_element(arr,arr+n);
    range++; //this is done so that in case range%k!=0 we do not cross k in the formula to find the index of the bucket.
    vector <ll> bkt[k];
    for(int i=0;i<n;i++)
    {
        int bi=(k*arr[i])/range;  //formula to decide the bucket to put the element in.
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++)
    {
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<bkt[i].size();j++)
        {
            arr[index]=bkt[i][j];
            index++;
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[]={20,25,10,5,30,36,41,45,50,59,60};
    int size=sizeof(arr)/sizeof(int);
    print(arr,size);
    bucket_sort(arr,size,4);
    print(arr,size);
    return 0;
}
