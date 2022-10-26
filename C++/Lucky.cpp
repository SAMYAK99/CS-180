// C++ program for Lucky Numbers

#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n)
{
	static int counter = 2;

	if (counter > n)
		return 1;
	if (n % counter == 0)
		return 0;

	int next_position = n - (n / counter);

	counter++;
	return isLucky(next_position);
}

int main()
{
	int x = 5;

	if (isLucky(x))
		cout << x << " is a lucky no.";
	else
		cout << x << " is not a lucky no.";
}
