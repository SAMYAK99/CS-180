// * * *    Square matrix, Using Star Symbol.
// * * *
// * * *
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nEnter the number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            cout << ("* ");
        }
        cout << endl;
    }
}