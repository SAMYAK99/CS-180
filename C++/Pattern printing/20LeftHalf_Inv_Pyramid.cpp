// * * * *  Left Half Inverted Pyramid.
// * * * 
// * *
// * 
#include<iostream>
using namespace std;
int main()
{
    int r;
    cout << "\nHow many row you want to print: ";
    cin >> r;
    for(int i=r; i>0; i--)
    {
        for(int j=i; j>0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}