int rec(int ind , int W , vector<int> &wt , vector<int> &val,vector<vector<int>> &dp)
{
    if(ind == 0)
    {
           if(wt[0] <= W) return val[0];
           return 0;
    }
    
    if(dp[ind][W] != - 1)
        return dp[ind][W];
    
    int pick = INT_MIN ;
    int notpick = rec(ind-1,W,wt,val,dp);
    
    if(wt[ind] <= W)
    {
         pick = val[ind] + rec(ind-1,W - wt[ind],wt,val,dp);
    }
    return dp[ind][W] = max(pick,notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n , vector<int> (maxWeight + 1 , -1));
    return rec(n-1,maxWeight,weight,value,dp);
}
