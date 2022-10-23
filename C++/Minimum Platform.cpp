#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
  for(auto it : v)
    cout << it << " ";
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> dep(n);
  int a,b;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    arr[i] = a;
    dep[i] = b;
  }
  sort(arr.begin(), arr.end()); //print(arr);
  sort(dep.begin(), dep.end()); //print(dep);
  int min_platforms=1, count=0;
  int i=0, j=0;
  while(i < n && j < n) {
    if(arr[i] <= dep[j]) {
      count++;
      i++;
    }
    else if(arr[i] > dep[j]) {
      count--;
      j++;
    }
    if(min_platforms < count)
      min_platforms = count;
  }
  cout << min_platforms << endl;
  return 0;
}
