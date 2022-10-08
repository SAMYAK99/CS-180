// A B C D  Square matrix, Each Columns contain the same N value.
// A B C D
// A B C D
// A B C D 
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << ("\nEnter number of rows: ");
    cin >> n;
    for(int r=1; r<=n; r++)
    {
        for(int c=1; c<=n; c++)
        {
            cout << ((char)(c + 64)) << (" ");
        }
        cout << endl;
    }
    return 0;
}