#include <bits/stdc++.h>
using namespace std;

int main(){
	int nd;
	cout << "How Many Digits Number Would you want to check : ";
	cin >> nd; 
	cout << endl;
	char number[nd], number2[nd];
	cout << "Input your number : ";
	for(int i=1; i<=nd; i++){
		cin >> number[i];
	} cout << endl;
	
	for(int i=1; i<=nd; i++)
	{
		number2[i] = number[nd+1-i];
	}

	// Check number value
	for(int i=1; i<=nd; i++)
	{
		if(number[i] != number2[i])
		{
			cout << "This number is not palindrome";
			return 0;
		}
	}
	cout << "This number palindrome"; 
	return 1; 
}
