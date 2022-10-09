// 1 1 1 Square Matrix, Each Rows contain the same value.
// 2 2 2 
// 3 3 3 
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
            cout << r << (" ");
        }
        cout << endl;
    }
    return 0;
}