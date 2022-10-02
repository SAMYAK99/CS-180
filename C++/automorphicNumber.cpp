//automorphic number

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, n1, i = 0;
        cin >> n;

        n1 = n;

        while (n > 0)
        {
            n /= 10;
            i++;
        }

        int d = pow(10, i);

        long sqr = n1 * n1;
        int rem1 = sqr % d;

        if (rem1 == n1)
            cout << "Automorphic" << endl;

        else
            cout << "Not Automorphic" << endl;
    }
}