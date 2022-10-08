// 1 1 1 1 1 
// 1 1 1 2 2 
// 1 1 3 3 3
// 1 4 4 4 4 
// 5 5 5 5 5 
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
            if(c>(n-r))
            cout << r << (" ");
            else 
            cout << ("1 ");
        }
        cout << endl;
    }
    return 0;
}