// A A A  Square Matrix, Rows contains the same n value.
// B B B 
// C C C 
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("Enter number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            cout << ((char)(r+64)) << (" ");
        }
        cout << endl;
    }
    return 0;
}