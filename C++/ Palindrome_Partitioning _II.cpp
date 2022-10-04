#include<bits/stdc++.h>
using namespace std;

    vector<vector<bool>> LPS;
    vector<vector<int>> DP;
    int helper(string &s, int i, int j){
        if(i == j || LPS[i][j]) return 0;
        
        if(DP[i][j] != -1) return DP[i][j];
        
        DP[i][j] = INT_MAX;
        for(int k = i; k<j; k++)
            if(LPS[i][k])
                DP[i][j] = min(DP[i][j], 1+helper(s, i, k)+helper(s, k+1, j));
        return DP[i][j];
    }
    int minCut(string s) {
        int n = s.size();
        LPS.resize(n, vector<bool>(n, true));
        DP.resize(n, vector<int>(n, -1));
        for(int i = 1; i<n; i++){
            int row = 0, col = i;
            while(col < n){
                if(s[row] == s[col]) LPS[row][col] = LPS[row+1][col-1];
                else LPS[row][col] = 0;
                row++, col++;
            }
        }
        return helper(s, 0, n-1);}
int main()
{
    string s;
    cout<<"Enter string";
    cin>>s;
    minCut(s);
    return 0;
}