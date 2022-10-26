// C program to find Armstrong number
#include <stdio.h>

// Function to calculate N raised
// to the power D
int power(int N, unsigned int D)
{
	if (D == 0)
		return 1;

	if (D % 2 == 0)
		return power(N, D / 2)
			* power(N, D / 2);

	return N * power(N, D / 2)
		* power(N, D / 2);
}

// Function to calculate the order of
// the number
int order(int N)
{
	int r = 0;

	// For each digit
	while (N) {
		r++;
		N = N / 10;
	}
	return r;
}


// number is Armstrong number or not
int isArmstrong(int N)
{
	// Calling order function
	int D = order(N);

	int temp = N, sum = 0;

	// For each digit
	while (temp) {
		int N1 = temp % 10;
		sum += power(N1, D);
		temp = temp / 10;
	}

	// If satisfies Armstrong condition
	if (sum == N)
		return 1;
	else
		return 0;
}

int main()
{
	// Given Number N
	int N = 153;

	// Function Call
	if (isArmstrong(N) == 1)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}
