//     1            1*1 = 1 - 1 = 0  r==1
//    121           2*2 = 4 - 1 = 3 
//   12321          3*3 = 6 - 1 = 5
//  1234321         4*4 = 8 - 1 = 7
// 123454321
#include<iostream>
using namespace std;
int main()
{
    int n, a;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n-r; c++)
        cout << " ";
        for(int k=1; k<=2*r-1; k++)
        {
            if(k<r) {
                cout << k;
            }
            else if(k==r)   {
                cout << k;
                a = k;
            }
            else {
                cout << --a;
            }
        }
        cout << endl;
    }
}