#include <iostream>
using namespace std;

/* This program is used to print all the prime numbers in a certain range,
   the upper and lower limits included.
*/

int main(){
    int p, q;
    cin >> p >> q; //taking the limits of the range as inputs
    int count;
    for(int i=p; i<=q; i++){ //iterating through the given range
        count = 0;
        for(int j=1; j<=i; j++){ //iterating from 1 to the number in the range
            if(i%j==0) //checking if j is a factor of the number
            count++; //counting the number of factors of the number
        }
        if(count==2) //if the number has two factors, it is prime and gets printed
        cout << i << " ";
    }
    return 0;
}
