// 1 2 3  Square matrix, Each Columns contain the same N value.
// 1 2 3
// 1 2 3 
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
            cout << c << (" ");
        }
        cout << endl;
    }
    return 0;
}