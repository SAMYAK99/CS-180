// *                Asterisk with Dollar Sign pattern.
// $ * 
// * $ *
// $ * $ *
// * $ * $ *
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        int flag=1;
        for(int c=1; c<=r; c++)
        {
            if((0 == r % 2 && c == 1) || flag == 0)
            {
                cout << "$ ";
                flag = 1;
            }
            else
            {
                cout << "* ";
                flag = 0;
            }
        }
        cout << endl;
    }
    return 0;
}