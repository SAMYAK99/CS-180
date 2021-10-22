#include <bits/stdc++.h>
using namespace std;

int main(){
	int temperatureNumber;
	string temperatureType, temperatureType2;
	cout << "==============================================================================" << endl;
	cout << "Input terperatur type list \nC (Celcius) \nR (Reamur) \nK (Kevlin) \nF (Fahrenheit)" << endl;
	cout << "Example Input (45 C K)" << endl;
	cout << "It means temperature change from Celcius to Kelvin" << endl;
	cout << "==============================================================================" << endl;
	cout << "Input : ";
	cin >> temperatureNumber;
	cin >> temperatureType;
	cin >> temperatureType2;

	// Temperature Convertion Code
	if(temperatureType == "C" or temperatureType == "Celcius"){
		if(temperatureType2 == "R" or temperatureType2 == "Reamur"){
			cout << 4 * temperatureNumber / 5; return 1;
		} else if (temperatureType2 == "K" or temperatureType2 == "Kelvin"){
			cout << temperatureNumber + 273; return 1;
		} else if(temperatureType2 == "F" or temperatureType2 == "Fahrenheit"){
			cout << (9 * temperatureNumber / 5) + 32; return 1;
		} else { cout << "Your second temperature input invalid"; return 0;}
	} else if(temperatureType == "R" or temperatureType == "Reamur"){
		if(temperatureType2 == "C" or temperatureType2 == "Celcius"){
			cout << 5 * temperatureNumber / 4; return 1;
		} else if (temperatureType2 == "K" or temperatureType2 == "Kelvin"){
			cout << (5 * temperatureNumber / 4) + 273; return 1;
		} else if(temperatureType2 == "F" or temperatureType2 == "Fahrenheit"){
			cout << (9 * temperatureNumber / 4) + 32; return 1;
		} else { cout << "Your second temperature input invalid"; return 0;}
	} else if(temperatureType == "K" or temperatureType == "Kelvin"){
		if(temperatureType2 == "C" or temperatureType2 == "Celcius"){
			cout << temperatureNumber - 273; return 1;
		} else if (temperatureType2 == "R" or temperatureType2 == "Reamur"){
			cout << 4 * (temperatureNumber - 273) / 5; return 1;
		} else if(temperatureType2 == "F" or temperatureType2 == "Fahrenheit"){
			cout << (9 * (temperatureNumber - 273) / 5) + 32; return 1;
		} else { cout << "Your second temperature input invalid"; return 0;}
	} else if(temperatureType == "F" or temperatureType == "Fahrenheit"){
		if(temperatureType2 == "C" or temperatureType2 == "Celcius"){
			cout << 5 * (temperatureNumber - 32) / 9; return 1;
		} else if (temperatureType2 == "R" or temperatureType2 == "Reamur"){
			cout << 4 * (temperatureNumber - 32) / 9; return 1;
		} else if(temperatureType2 == "K" or temperatureType2 == "Kelvin"){
			cout << (9 * (temperatureNumber - 32) / 5) + 273; return 1;
		} else { cout << "Your second temperature input invalid"; return 0;}
	} else { cout << "Your temperature input invalid"; return 0;}
}







