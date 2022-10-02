class Solution{ 
    public: int kthElement(int arr1[], int arr2[], int n, int m, int k) 
    { 
    int num = m+n; 
    int arr[num]; 
    for(int i=0;i<n;i++) 
        arr[i] = arr1[i];
    for(int i=0;i<m;i++)
        arr[n+i]=arr2[i];
    sort(arr,arr+num); 
    return arr[k-1]; 
    }
    };
