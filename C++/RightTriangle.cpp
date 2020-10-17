#include <iostream>
  
using namespace std;
  
int main() {
    int i,j,n;
 
    cout << "Input N: ";
    cin >> n;
 
    for (i=1;i<=n;i++) {
        for (j=1;j<=i;j++) {
            cout << "*";
        }
        cout << endl;
    }
  
    return 0;
}
