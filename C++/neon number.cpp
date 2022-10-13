// C/C++ program to check and print
// Neon Numbers upto 10000
#include <iostream>
using namespace std;
#include <math.h>

int checkNeon(int x)
{
	// storing the square of x
	int sq = x * x;

	// calculating the sum of digits
	// of sq
	int sum_digits = 0;
	while (sq != 0) {
		sum_digits = sum_digits + sq % 10;
		sq = sq / 10;
	}
	return (sum_digits == x);
}

// Driver Code
int main(void)
{
	// Printing Neon Numbers upto 10000
	for (int i = 1; i <= 10000; i++)
		if (checkNeon(i))
			cout << i << " ";
}
