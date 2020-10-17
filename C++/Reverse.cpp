#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int num,rem,rev = 0;

    cout<<"enter a number \n";
    cin>>num;

    while(num!=0){
        rem = num%10;
        rev = rev*10+rem;
        num = num/10;

    }
    cout<<"after reverse "<<rev;

	return 0;
}