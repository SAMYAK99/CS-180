// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if
// n is a Dudeney number
bool isDudeney(int n)
{
	int cube_rt = int(round((pow(n, 1.0 / 3.0))));

	// If n is not a perfect cube
	if (cube_rt * cube_rt * cube_rt != n)
		return false;

	int dig_sum = 0;
	int temp = n;
	while (temp > 0) {

		// Last digit
		int rem = temp % 10;

		// Update the digit sum
		dig_sum += rem;

		// Remove the last digit
		temp /= 10;
	}

	// If cube root of n is not equal to
	// the sum of its digits
	if (cube_rt != dig_sum)
		return false;

	return true;
}

// Driver code
int main()
{
	int n = 17576;
	if (isDudeney(n))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
