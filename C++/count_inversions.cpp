#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long tmp[],long long left,long long mid,long long right)
    {
        long long i=left;
        long long j=mid+1;
        long long k=left;
        long long inv=0;
        while(i<=mid&&j<=right)
        {
            if(arr[i]<=arr[j])
            {
             tmp[k++]=arr[i++];   
            }
            else
            {
             inv+=((mid+1)-i);
             tmp[k++]=arr[j++];
            }
        }
        while(i<=mid)
        {
            tmp[k++]=arr[i++];
        }
        while(j<=right)
        {
            tmp[k++]=arr[j++];
        }
        for(int m=left;m<=right;m++)
        arr[m]=tmp[m];
        return inv;
    }
    long long mergesort(long long arr[],long long tmp[],long long left,long long right)
    {
        long long inv=0;
        if(left<right)
        {
            int mid=(left+right)/2;
            inv+=mergesort(arr,tmp,left,mid);
            inv+=mergesort(arr,tmp,mid+1,right);
            inv+=merge(arr,tmp,left,mid,right);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long  tmp[N];
        return mergesort(arr,tmp,0,N-1);
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
