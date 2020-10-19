#include <bits/stdc++.h>
using namespace std;

int main(){
	int numberDigits;
	cout << "How Many Digits Number Would you want to check : ";
	cin >> numberDigits; cout << endl;
	char number[numberDigits], number2[numberDigits];
	cout << "Input your number : ";
	for(int i=1; i<=numberDigits; i++){
		cin >> number[i];
	} cout << endl;
	
	// change value inverse
	for(int i=1; i<=numberDigits; i++){
		number2[i] = number[numberDigits+1-i];
	}

	// Check number value
	for(int i=1; i<=numberDigits; i++){
		if(number[i] != number2[i]) { cout << "This number is not palindrome"; return 0;}
	}
	cout << "This number palindrome"; return 1; 
}
