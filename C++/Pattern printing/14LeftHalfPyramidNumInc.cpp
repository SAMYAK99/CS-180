// 1 
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
#include<iostream>
using namespace std;
int main()
{
    int n, x=1;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=r; c++)
        {
            cout << x << " ";
            x++;
        }
        cout << endl;
    }
    return 0;
}
