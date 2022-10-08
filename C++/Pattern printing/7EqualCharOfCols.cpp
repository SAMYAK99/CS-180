// a b c d  Square Matrix, Each Columns contain the same value
// a b c d
// a b c d
// a b c d
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nEnter number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            cout << ((char)(96+c)) << (" ");
        }
        cout << endl;
    }
    return 0;
}