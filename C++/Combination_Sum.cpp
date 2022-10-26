// problem link: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void combinationSumHelp(int ind,int target,vector<int> & candidates,vector<vector<int>> & ans, vector<int> & a)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(a);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            a.push_back(candidates[ind]);
            combinationSumHelp(ind,target-candidates[ind],candidates,ans,a);
            a.pop_back();
        }
        combinationSumHelp(ind+1,target,candidates,ans,a);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        combinationSumHelp(0,target,candidates,ans,a);
        return ans;
    }
};

