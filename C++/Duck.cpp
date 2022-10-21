// A number is Duck Number or not.
#include <iostream>
using namespace std;

// Function to check whether
// given number is duck number or not.
bool check_duck(string num)
{
	// Ignore leading 0s
	int i = 0, n = num.length();
	while (i < n && num[i] == '0')
		i++;

	// Check remaining digits
	while (i < n) {
		if (num[i] == '0')
			return true;
		i++;
	}

	return false;
}

// Driver Method
int main(void)
{
	string num = "1023";
	if (check_duck(num))
		cout << "It is a duck number\n";
	else
		cout << "It is not a duck number\n";

	return 0;
}
