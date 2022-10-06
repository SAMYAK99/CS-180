int Solution::solve(const vector<int> &A) {
    int ans=2;
    int n=A.size();
    if(n<=2)return n;
    unordered_map<int,int>mp;
    int dp[1001][1001];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=2;
            int prev=2*A[i]-A[j];
            if(mp.find(prev)!=mp.end())
            {
                dp[i][j]=max(dp[i][j],1+dp[mp[prev]][i]);
                ans=max(ans,dp[i][j]);
            }
        }
        mp[A[i]]=i;
    }
    return ans;
}