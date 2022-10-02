// C++ code for finding greater 
// between the a^n and b^n 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the greater value 
void findGreater(int a, int b, int n) 
{ 
	// If n is even 
	if (!(n & 1)) { 

		a = abs(a); 
		b = abs(b); 
	} 
	if (a == b) 
		cout << "a^n is equal to b^n"; 

	else if (a > b) 
		cout << "a^n is greater than b^n"; 

	else
		cout << "b^n is greater than a^n"; 
} 

// Driver code 
int main() 
{ 
	int a = 12, b = 24, n = 5; 
	findGreater(a, b, n); 
	return 0; 
} 
