#include <iostream>
using namespace std;

int factorial(int num);
int C(int n, int r);
int main(){

    int input;
    cout << "INPUT : ";
    cin >> input;

    for(int i = 0; i < input; i++){
        for(int j = 0; j < input-i+1; j++){
            cout << " ";
        }

        for(int j = 0; j <= i; j++){
            int temp;
            temp = C(i,j);
            cout << temp << " ";
        }
        cout << endl;
    }
    
    return 0;
}

int factorial(int num){
    int val = 1;
    for(int i = num; i > 1; i--){
        val = val*i;
    }

    return val;
}
int C(int n, int r){
    int a, b, c;
    a = factorial(n);
    b = factorial(n-r);
    c = factorial(r);

    int val;
    val = a/(b*c);

    return val;
}