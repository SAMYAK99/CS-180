// *             *  Right-Left half Pyramd.
// * *         * *
// * * *     * * *
// * * * * * * * * kacchi basti - barkat colony - right hand - got-it.
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nHow many row you want to print: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=2*n; c++)
        {
            if(c<=r || c>(2*n-r))
            cout << ("* ");
            else
            cout << ("  ");
        }
        cout << endl;
    }
    return 0;
}