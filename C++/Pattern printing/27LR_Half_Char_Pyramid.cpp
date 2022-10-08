// ABCDCBA            1-4 & 5-7
// ABC CBA              1-3 & 5-7
// AB   BA
// A     A
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=n; r>=1; r--)
    {
        for(int c=1; c<=2*n-1; c++)
        {
            if(c<=r) {
                cout << ((char)(64+c)) << " ";
                if(c==r)
                a = c;
            }
            else if(c>(2*n)-r && r == n) {
                --a;
                cout << ((char)(64+a)) << " ";
            }
            else if(c>=(2*n)-r) {
                cout << ((char)(64+a)) << " ";
                --a;
            }
            else    {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}