// a a a  Square Matrix, Rows contain the same N value.
// b b b 
// c c c 
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nEnter number of rows in Alphabet form: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            cout << ((char)(r+96));
        }
        cout << endl;
    }
    return 0;
}