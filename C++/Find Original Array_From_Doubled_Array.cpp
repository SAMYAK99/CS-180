//link to problem-https://leetcode.com/problems/find-original-array-from-doubled-array/



class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        map<int,int>mpp;
         
          vector<int>res;
        sort(changed.begin(),changed.end());
      
        for(auto it:changed)
            mpp[it]++;
       
      for(auto it:changed)
      {
          if(mpp[it])
          {
              res.push_back(it);
              mpp[it]--;
              if(mpp[2*it])
              mpp[2*it]--;
              else
                  return {};
          }
        
      }
        
      return res;  
    }
};
