
#include <stdio.h>
#include <stdlib.h> 

int reverseNumber(int num)
{
	int rev = 0;
	while (n> 0) {
		rev = rev* 10 + n % 10;
		n = n / 10;
	}
	return rev;
}

int isPalindrome(int n)
{
	int rev = reverseNumber(n);

	if (n == rev)
		return 1;
	else
		return 0;
}


int main(int argc, char* argv[])
{

	int num, res = 0;
	if (argc == 1)
		printf("No command line arguments found.\n");

	else {

		num = atoi(argv[1]);

		res = isPalindrome(num);
		if (res == 0)
			// Print No
			printf("No\n");
		else
			// Print Yes
			printf("Yes\n");
	}
	return 0;
}
