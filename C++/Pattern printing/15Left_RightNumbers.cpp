// 1
// 3 2 
// 4 5 6 
// 10 9 8 7
#include<iostream>
using namespace std;
int main()
{
    int n, x=1, flag=1;
    cout << "\nEnter number of rows: ";
    cin >> n;
    for(int r=1, y=0; r<=n; r++)
    {
        int a = y + 1;
        y = y + r;
        int z = y;
        for(int c=1; c<=r; c++)
        {
            if(0 == flag % 2 || r==1)
            {
                cout << z << " ";
                z--;
            }
            else
            {
                cout << a << " ";
                a++;
            }
        }
        flag++;
        cout << endl;
    }
    return 0;
}