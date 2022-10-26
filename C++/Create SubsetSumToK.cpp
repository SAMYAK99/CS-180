bool rec(int i ,int target , vector<int> &arr , vector<vector<int>> &dp)
{
    if(target == 0) 
        return true;
    
    if(i == 0)
    {
        if(arr[0] == target)
            return true;
        else 
            return false;
    }
    
    if(dp[i][target] != -1)
        return dp[i][target];
    
    bool take = false , nottake = false;
    
    if(target >= arr[i])
    take = rec(i-1,target - arr[i],arr,dp);
    
    nottake = rec(i-1,target,arr,dp);
  
    return dp[i][target] = (take | nottake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return rec(n-1,k,arr,dp);
}
