#include<iostream>
using namespace std;

    int solve(int i,int j,vector<int>& nums,vector<vector<int>>&t){
        if(i>j)return 0;
        int maxi=INT_MIN;
        if(t[i][j]!=-1)return t[i][j];
        for(int k=i;k<=j;k++){
           int coin=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,t)+solve(k+1,j,nums,t);
            if(coin>maxi)maxi=coin;
        }return t[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,t);
    }
int main()
{
    
    return 0;
}
