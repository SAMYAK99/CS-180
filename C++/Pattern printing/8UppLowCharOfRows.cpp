// a a a a  Square Matrix, 
// B B B B  Upper & Lower casee characters but in alternate rows.
// c c c c 
// D D D D 
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
            if(0 == r % 2)
            cout << ((char)(64+r)) << (" ");
            else
            cout << ((char)(96+r)) << (" ");
        }
        cout << endl;
    }
    return 0;
}