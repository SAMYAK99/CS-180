// PS:
//  Given an array consisting of the cost of toys.
// Given an integer K depicting the amount of money available to purchase toys.
//  Write a program to find the maximum number of toys one can buy with the amount K.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lt long long
#define pi (3.141592653589)
#define mod 1000000007

#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

#define lull NULL

#define float double

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define all(c) c.begin(), c.end()

#define min3(a, b, c) min(c, min(a, b))

#define min4(a, b, c, d) min(d, min(c, min(a, b)))

#define fir(i, n) for (int i = n - 1; i >= 0; i--)

#define fi(i, n) for (int i = 0; i < n; i++)
#define fin(j, n) for (int i = j; i <= n; i++)

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// This functions returns the required number of toys
int maximum_toys(vector<int> &cost, int N, int K)
{
    int count = 0, sum = 0;

    // sort the cost array
    sort(cost.begin(), cost.end());
    for (int i = 0; i < N; i++)
    {

        // Check if we can buy ith toy or not
        if (sum + cost[i] <= K)
        {
            sum = sum + cost[i];
            // Increment count
            count++;
        }
    }
    return count;
}

int main()
{
    int k, n;
    cin >> n >> k;

    vector<int> arr(n);
    fi(i, n)
    {
        cin >> arr[i];
    }
    cout << maximum_toys(arr, n, k) << endl;
    return 0;
}
