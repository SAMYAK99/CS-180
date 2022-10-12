
#include <iostream>
#include <vector>
  
using namespace std;
 
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
 
int main()
{
    vector<vector<int>> o;
    vector<strings> v;
    int n;
    cout<<"Enter the number of strings ";
    cin>>n;
    cout<<"Enter the strings ";

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    o=group_identical_strings(v);
    for(i=0;i<n;i++){
        cout<<o[i]<<endl;
    }
    return 0;
=======
#include "string.h"
main()
{
  char x[100] = "Amit Hanish Mahesh Amit";
  char y[3][100];
  int i = 0, k = 0, j = 0, c = 0, end, t;
  int current = 1;
  while (x[i] != '\0') {
    if (x[i] != ' ') {
      y[k][j] = x[i];
      j++;
      i++;
    } else {
      // c = c + 1;
      i++;
      k++;
      j = 0;
    }
    y[k][j] = '\0';
  }

  for (end = 1; end <= 3; end++) {
    for (t = 0; t < end; t++) {
      if (strcmp(y[end], y[t]) == 0) break;
    }
    if (end == t) {
      strcpy(y[current],y[t]);
       current++;
    }
  }
  y[current] = 0;
  cout<<y;
}