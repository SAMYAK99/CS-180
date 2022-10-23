#include <bits\stdc++.h>
using namespace std;

/*int max(int a, int b)
{
    return (a > b) ? a : b;
}*/

int knapsack(int size, int wt[], int val[], int n)
{
    int i, j;
    int p[n + 1][size + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= size; j++)
        {
            if (i == 0 || j == 0)
            {
                p[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                p[i][j] = max(val[i - 1] + p[i - 1][j - wt[i - 1]], p[i - 1][j]);
            }
            else
            {
                p[i][j] = p[i - 1][j];
            }
            cout << p[i][j] << "  ";
        }
        cout << endl;
    }
    return p[n][size];
}

int main()
{
    int wt[] = {12, 2, 4, 1, 1};
    int p[] = {4, 2, 10, 2, 1};
    int size = 20;
    int n = sizeof(p) / sizeof(p[0]);
    int maximum = knapsack(size, wt, p, n);
    cout << "\nMax Profit: " << maximum;
    return 0;
}