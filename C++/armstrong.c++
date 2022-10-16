#include <iostream>
using namespace std;

int main() {
    int number, originalNum, remainder, result = 0;
    cout << "Enter a three-digit integer: ";
    cin >> number;
    originalNumber = number;

    while (originalNumber != 0) {
        // remainder contains the last digit
        remainder = originalNumber % 10;
        
        result += remainder * remainder * remainder;
        
        // removing last digit from the orignal number
        originalNumber /= 10;
    }

    if (result == number)
        cout << number << " is an Armstrong number.";
    else
        cout << number << " is not an Armstrong number.";

    return 0;
}
