#include<bits/stdc++.h>

using namespace std;

void computePolynomial(int *, int *, int *, int, int);

int main() {

    //Maximum Power
    int n;

    //Polynomial Array
    int *a, *b;

    //Product Coefficients
    int *c;

    cout << "\nEnter the degree of the polynomial : ";
    cin >> n;

    //Allocating Memory
    a = new int[n + 1];
    b = new int[n + 1];
    c = new int[2*n + 1];
    
    for(int i = 0; i <= 2*n; i++) {
        c[i] = 0;
    }

    //Take the polynomial
    cout << "Enter the value of the coefficents for first polynomial: ";
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << "Enter the value of the coefficents for second polynomial: ";
    for(int i = 0; i <= n; i++) {
        cin >> b[i];
    }

    computePolynomial(a, b, c, 0, n);
    
    string str = "";
    for(int i = 2*n; i >= 0 ; i--) {
        str += to_string(c[i]) + "*" + "(x^" + to_string(i) + ")";

        if(i - 1 >= 0) {
            str += " + ";
        }
    }
    str += "\n\n";

    cout << "\nThe polynomial is : " << str;

    return 0;
}


/*
* We will divide the array into 2 parts
*                    Left      Right
* Polynomial 1 -> |a1*(x^p)|a2*(x^(p+1))|
* Polynomial 2 -> |b1*(x^p)|b2*(x^(p+1))|
* There are the following three parts:-
* 1. Left left Multiplication gives the coefficents for x^(2p) (Left)
* 2. Left right Multiplication gives the coefficents for x^(2p + 1) (Cross)
* 3. Right right Multiplication gives the coefficents for x^(2p + 2) (Right)
*/
void computePolynomial(int *a, int *b, int *c, int start, int end) {
    //Base Case
    if(start == end) {
        c[2*start] += a[start]*b[start];
        return;
    }
    else {
        int mid = (start + end)/2;
        
        //Left
        computePolynomial(a, b, c, start, mid);
        //Right
        computePolynomial(a, b, c, mid + 1, end);

        //Cross Calculation
        for(int i = start; i <= mid; i++) {
            for(int j = mid + 1; j <= end; j++) {
                c[i + j] += a[i]*b[j];
                c[i + j] += a[j]*b[i];
            }
        }
        
        return;
    }
}
