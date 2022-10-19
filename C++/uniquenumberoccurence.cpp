#include<map>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      int n=arr.size();
      map<int,int>count;
        set<int>ans;
      for(int i=0;i<n;i++)
      {
          count[arr[i]]++;
      }
      for(auto i =count.begin();i!=count.end();i++)
      {
          ans.insert(i->second);
      }
      return ans.size()==count.size();
    }
  
};
