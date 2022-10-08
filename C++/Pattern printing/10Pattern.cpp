// * * * * * 
// * A B C * 
// * D E F * 
// * G H I * 
// * * * * *
#include<iostream>
using namespace std;
int main()
{
    int n, x=1;
    cout << ("\nEnter number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            if(r == 1 || r == n|| c == 1 || c == n)
            {
                cout << ("* ");
            }
            else 
            {
                cout << ((char)(64+x)) << (" ");
                x++;
            }
        }
        cout << endl;
    }
    return 0;
}