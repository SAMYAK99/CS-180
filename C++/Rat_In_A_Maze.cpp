//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
       vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==0||m[n-1][n-1]==0)
        return res;
        int di[]={-1,0,+1,0};
        int dj[]={0,+1,0,-1};
        findit(m,n,res,0,0,"",vis,di,dj);
        sort(res.begin(),res.end());
        return res;
    }
    
    void findit(vector<vector<int>> &m, int n,vector<string> &res,int i,int j,string move,vector<vector<int>> &vis,int di[],int dj[])
{
   
    if(i==n-1&&j==n-1)
    {
        res.push_back(move);
        return;
        
    }
     string str="URDL";
    
    
    for(int ind=0;ind<4;ind++)
    {
        int indi=i+di[ind];
        int indj=j+dj[ind];
        
        
        if(indi>=0&&indj>=0&&indi<n&&indj<n&&vis[indi][indj]==0&&m[indi][indj]==1)
        {  vis[i][j]=1;
            findit(m,n,res,indi,indj,move+str[ind],vis,di,dj);
            vis[i][j]=0;
        }
    }
}
    
    
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
