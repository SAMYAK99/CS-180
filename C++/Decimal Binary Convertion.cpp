#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int convertType, number;
	cout << "==============================================================================" << endl;
	cout << "Input Number type list \nConvert Decimal To Binary (1) \nConvert Binary To Decimal (2)" << endl;
	cout << "Example Input (1 100)" << endl;
	cout << "It means number change from Decimal to Binary" << endl;
	cout << "==============================================================================" << endl;
	cout << "Input : ";
	cin >> convertType;
	
	//Convertion Code
	if(convertType == 1){
		int binary[20];
		cin >> number;
		
		// Change from decimal to binary
		int x = 0;
		while(number > 0){
			binary[x] = number % 2;
			number /= 2;
			x++;
		}

		// Print output
		 x-= 1;
		while(x >= 0){
			cout << binary[x];
			x--;
		} 
	} else if(convertType == 2){
		cin >> number;
		int binary2[20];
		
		//Takes separated number
		int i = 1;
		while(number > 0){
			binary2[i] = number % 10;
			number /= 10;
			i++;
		}
		
		//Change from binary to decimal
		int decimal = 0;
		int j = 0;
		i--;
		while(i > 0){
			decimal += binary2[j+1] * pow(2,j);
			i--, j++;
		}
		cout << decimal;
	}
}
