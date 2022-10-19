class Solution {
public:
    
      int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i==0 && j ==0)
            return grid[0][0];
        if(i<0 || j<0)
            return 2147483546;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = f(i-1,j,dp,grid) + grid[i][j];
        int up = f(i,j-1,dp,grid) + grid[i][j];
        
        return dp[i][j] = min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,dp, grid);
    }
};