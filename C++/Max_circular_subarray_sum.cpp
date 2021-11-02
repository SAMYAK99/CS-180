
// C++ program for maximum contiguous circular sum problem
#include <bits/stdc++.h>
using namespace std;

// Standard Kadane's algorithm to
// find maximum subarray sum
int kadane(int a[], int n);

// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane'
    // s algorithm
    int max_kadane = kadane(a, n);
     // if maximum sum using standard kadane' is less than 0
    if(max_kadane < 0)
      return max_kadane;

    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int max_wrap = 0, i;
    for (i = 0; i < n; i++) {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i]; // invert the array (change sign)
    }

    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);

    // The maximum circular sum will be maximum of two sums
    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}

// Standard Kadane's algorithm to find maximum subarray sum
// See https:// www.geeksforgeeks.org/archives/576 for details
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
          if (max_ending_here < 0)
              max_ending_here = 0;
    }
    return max_so_far;
}

/* Driver program to test maxCircularSum() */
int main()
{
    int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl;
    return 0;
}

// This is code is contributed by rathbhupendra
