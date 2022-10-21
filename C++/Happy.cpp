// C++ program to check a number is a Happy number or not
#include <bits/stdc++.h>
using namespace std;

// Method to return sum of square of digit of n
int numSquareSum(int n)
{
	int squareSum = 0;
	while (n) {
		squareSum += (n % 10) * (n % 10);
		n /= 10;
	}
	return squareSum;
}


bool isHappynumber(int n)
{
	int slow, fast;

	slow = fast = n;
	do {
		slow = numSquareSum(slow);
		fast = numSquareSum(numSquareSum(fast));
	} while (slow != fast);
	return (slow == 1);
}

int main()
{
	int n = 13;
	if (isHappynumber(n))
		cout << n << " is a Happy number\n";
	else
		cout << n << " is not a Happy number\n";
}

