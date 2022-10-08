// * * * *  Right Half Inverted Pyramid.
//   * * *
//     * *
//       *
#include<iostream>
using namespace std;
int main()
{
    int r;
    cout << "\nHow many row you will enter in a row: ";
    cin >> r;
    for(int i=r; i>0; i--)
    {
        for(int j=r; j>i; j--)
        {
            cout << "  ";
        }
        for(int k=0; k<i; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}