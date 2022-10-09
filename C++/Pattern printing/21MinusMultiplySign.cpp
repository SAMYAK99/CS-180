// - - - - *
// - - - * *
// - - * * *
// - * * * *
// * * * * *
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            if(c > n-r)
            cout << "* ";
            else
            cout << "- ";
        }
        cout << endl;
    }
    return 0;
}