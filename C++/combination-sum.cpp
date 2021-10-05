//link to problem-https://leetcode.com/problems/combination-sum/


class Solution {
public:
    
  
    vector<int>v1;
    
    void find(int ind,int n,vector<int>& candidates,int target,vector<vector<int>>&v)
    {
        if(ind==n)
        {
         if(target==0)
         
            v.push_back(v1);
         
            return ;
         }
        
        if(target-candidates[ind]>=0)
        {
            //pick
            v1.push_back(candidates[ind]);
            find(ind,n,candidates,target-candidates[ind],v);
            v1.pop_back();
        }
        
        find(ind+1,n,candidates,target,v);//non pick
        
    }
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> v;
        
        find(0,candidates.size(), candidates,target, v);
        return v;
    }
};
