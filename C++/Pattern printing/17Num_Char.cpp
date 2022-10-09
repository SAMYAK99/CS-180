// A                    Number with Char pyramid pattern.
// 1 1 
// B B B 
// 2 2 2 2
// C C C C C
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
            if(0 == r % 2)
            {
                cout << x << " ";
                if(c == r)
                x++;
            }
            else
            cout << ((char)(64+x)) << " ";
        }
        cout << endl;
    }
    return 0;
}