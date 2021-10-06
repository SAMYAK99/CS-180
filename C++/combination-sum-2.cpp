//link to problem-https://leetcode.com/problems/combination-sum-ii/


class Solution {
public:
    
    void find(int ind,int n,vector<int>arr,int target,vector<vector<int>>&v1,vector<int>&v)
    {
        if(target==0)
        {
            v1.push_back(v);
            return;
        }
        
       for(int i=ind;i<n;i++)
       {
           if(i>ind&&arr[i]==arr[i-1])
               continue;
           if(arr[i]>target)
               break;
               
           
               v.push_back(arr[i]);
               find(i+1,n,arr,target-arr[i],v1,v);
               v.pop_back();
           
       //  if()
           
            
       }//find(ind+1,n,arr,target,v1,v);
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        
        vector<int>v;
        vector<vector<int>>v1;
        sort(candidates.begin(),candidates.end());
        find(0,candidates.size(),candidates,target,v1,v);
        return v1;
        
    }
};
