#include <bits/stdc++.h>
using namespace std;

void towerOfBrahma(int s, int h, int d, int n, int &ct);

int main()
{
    int n; cin>>n;
    int source = 1;
    int helper = 2;
    int destination = 3;
    int steps = 0;
    towerOfBrahma(source, helper, destination, n, steps);
    cout<<"Steps: "<<steps<<endl;
    return 0;
}

void towerOfBrahma(int s, int h, int d, int n, int &ct)
{
    ct++;
    if(n == 1){
        cout<<"Moving plate: "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    towerOfBrahma(s, d, h, n-1, ct);
    cout<<"Moving plate: "<<n<<" from "<<s<<" to "<<d<<endl;
    towerOfBrahma(h, s, d, n-1, ct);
      
}
