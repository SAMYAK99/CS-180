#include <iostream>
using namespace std;

int strlength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string addBitStrings(string first, string second)
{
    string final;

    int length = strlength(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        int sum = (firstBit ^ secondBit ^ carry) + '0';

        final = (char)sum + final;

        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry == 1)
        final = '1' + final;

    return final;
}

int multiplyiSingleBit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

long int multiply(string X, string Y)
{

    int n = strlength(X, Y);

    if (n == 0)
        return 0;
    if (n == 1)
        return multiplyiSingleBit(X, Y);

    int fh = n / 2;
    int sh = (n - fh);

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main()
{
    int option;
    do
    {
        cout << "Enter 1 to multiply two binary strings" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> option;
        if (option == 1)
        {
            string str1, str2;
            cout << "Enter binary string 1: ";
            cin >> str1;
            cout << "Enter binary string 2: ";
            cin >> str2;
            cout << multiply(str1, str2) << endl;
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid option!!!" << endl;
        }

    } while (option != 0);
}
