//Floyd's Triangle

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[100][100];
        int k = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                arr[i][j] = k;
                cout << arr[i][j] << " ";
                k++;
            }
            cout << endl;
        }


    }
    //code
    return 0;
}
