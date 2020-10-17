
#include <iostream>
#include <cmath>

using namespace std;

int main(){

int year;

cout<<"enter year\n";
cin>>year;

if(year%4==0){
    if(year%100==0){
        if(year%400==0)
            cout<<"it is a leap year\n";

        else
            cout<<"not a leap year\n";
    }
    else
    cout<<"it is a leap year\n";
    }
else
    cout<<"not a leap year\n";


	return 0;
}