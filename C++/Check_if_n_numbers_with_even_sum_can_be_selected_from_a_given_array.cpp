// C++ efficient program to check
// if N numbers with Odd sum can be
// selected from the given array
#include <bits/stdc++.h>
using namespace std;

// Function to check if an odd sum can be
// made using N integers from the array
bool checkEvenSum(int arr[], int N, int size)
{
	// Initialize odd and even counts
	int even_freq = 0, odd_freq = 0;

	// Iterate over the array to count
	// the no. of even and odd integers
	for (int i = 0; i < size; i++) {
		// If element is odd
		if (arr[i] & 1)
			odd_freq++;

		// If element is even
		else
			even_freq++;
	}

	// Check if even_freq is more than N
	if (even_freq >= N)
		return true;
	else {

		// If odd_freq is odd
		if (odd_freq & 1) {

			// Consider even count of odd
			int taken = odd_freq - 1;

			// Calculate even required
			int req = N - taken;

			// If even count is less
			// than required count
			if (even_freq < req) {
				return false;
			}
			else
				return true;
		}
		else {

			int taken = odd_freq;

			// Calculate even required
			int req = N - taken;

			// If even count is less
			// than required count
			if (even_freq < req) {
				return false;
			}
			else
				return true;
		}
	}

	return false;
}

// Driver Code
int main()
{
	int arr[] = { 9, 2, 3, 4, 18, 7, 7, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int N = 5;

	if (checkEvenSum(arr, N, size))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
