//Recursive binary search program
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
	if(r >= l)
        {
	    int mid = l + (r - l) / 2;
            if(arr[mid] == x)
	    {
	       return mid;//If mid index element matches x
	    }
	    else if(arr[mid] > x)
	    {
	       return binarySearch(arr, l, mid - 1, x);//Search in left half
	    }
	    return binarySearch(arr, mid + 1, r, x);//Search in right half 
	}
	return -1;
}

int main(void)
{
    int n;
    cout<<"Enter array size:"<<endl;
    cin>>n;//Array size
    vector<int> arr(n);//Input array
    cout<<"Enter "<<n<<" array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];//Array elements
    }
    int x;
    cout<<"Enter element for searching:"<<endl;
    cin>>x;//Search element
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1)
    {
       cout<<"Element doesn't exist in array"<<endl;
    }
    else
    {
       cout<<"Element is present in array and at index: "<<result<<endl;
    }
    return 0;
}

//Time complexity: O(logn)
//Auxiliary Space complexity: O(logn) for recursive stack calls.
//Note:- Binary search can be used only when array is sorted.
