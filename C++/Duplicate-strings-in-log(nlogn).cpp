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
}