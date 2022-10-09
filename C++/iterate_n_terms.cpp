#include <iostream>
using namespace std;
#define N 100

void printNum(int n)
{
    if (n <= 0) {
        return;
    }

    printNum(n - 1);
    cout << n << " ";
}

int main()
{
    printNum(N);
    return 0;
}