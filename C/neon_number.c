
// a number is Neon number or not
#include <stdio.h>

int Check_Neon(int num) {

	int square = num * num;
	int n = square;
	int digit;
	int sum = 0;
	while (n != 0) {

		digit = n % 10;
		sum = sum + digit;
		n = n / 10;
	}
	if (sum == num)
		return 1; 
	else
		return 0; 
}

// Driver Code
int main()
{
	int num = 9;

	// Calling the function
	int ans = Check_Neon(num);
	if (ans == 1)

		// is Neon
		printf("yes");
	else

		//  not Neon
		printf("no");
	return 0;
}
