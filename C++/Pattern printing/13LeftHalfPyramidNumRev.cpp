// 1
// 2 1 
// 3 2 1
// 4 3 2 1
// 5 4 3 2 1
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nEnter number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=r; c>=1; c--)
        {
            cout << c << (" ");
        }
        cout << endl;
    }
    return 0;
}