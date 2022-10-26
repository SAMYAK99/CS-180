// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the median
double findMedianSortedVectors(vector<int>& a,
							vector<int>& b)
{
	// New Vector of size a + b
	vector<int> c(a.size() + b.size());
	int k = 0;
	double median = 0;
	int size_a = a.size();
	int size_b = b.size();
	for (int i = 0; i < size_a; i++)
	{
		// Store data of first vector
		// in new vector
		c[k++] = a[i];
	}
	for (int i = 0; i < size_b; i++)
	{
		// Store second vector in
		// vector c
		c[k++] = b[i];
	}

	merge(a.begin(), a.end(),
		b.begin(), b.end(), c.begin());

	// Merge the both sorted vectors
	int n = c.size();
	if (n % 2 == 0)
	{
		// Calculate median for even
		// size vector
		median = c[(n / 2) - 1] + c[n / 2];
		median = median / 2;
	}
	else
	{
		// Calculate median for odd
		// size vector
		median = c[(n - 1) / 2];
	}
	return median;
}

// Driver code
int main()
{
	vector<int> v1;
	vector<int> v2;

	// Initialize first vector
	v1.push_back(1);
	v1.push_back(4);

	// Initialize second vector
	v2.push_back(2);

	// Invoke function to calculate
	// median
	double median_vectors =
	findMedianSortedVectors(v1, v2);

	// Print median value
	cout << median_vectors << endl;
	return 0;
}
