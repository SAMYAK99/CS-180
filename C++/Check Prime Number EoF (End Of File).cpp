#include <bits/stdc++.h>
using namespace std;

int main(){
	int maxNumberInput = 1000;
	char a[maxNumberInput];
	cin.getline(a,maxNumberInput);
	
	int i = 0;
	while(a[i] != '\0'){
		if(a[i] != ' '){
			int b = a[i]-'0';
			int divider = 0;
			for(int j=1; j<=b; j++){
				if(b % j == 0){ divider++;}
				if(divider >= 3){ break; }
			}
			if(divider == 2){cout << "Prime Number" << endl;}
			else if( divider > 2){ cout << "It is not a prime number" << endl; }
		}
	i++;
	}
}
