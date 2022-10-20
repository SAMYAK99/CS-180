// A Naive C++ program to find maximum sum rotation
#include<bits/stdc++.h>

using namespace std;

// Returns maximum value of i*arr[i]
int maxSum(int arr[], int n)
{
// Initialize result
int res = INT_MIN;

// Consider rotation beginning with i
// for all possible values of i.
for (int i=0; i<n; i++)
{

	// Initialize sum of current rotation
	int curr_sum = 0;
	for (int j=0; j<n; j++)
	{
		int index = (i+j)%n;
		curr_sum += j*arr[index];
	}

	// Update result if required
	res = max(res, curr_sum);
}

return res;
}

// Driver code
int main()
{
	int arr[] = {8, 3, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxSum(arr, n) << endl;
	return 0;
}
