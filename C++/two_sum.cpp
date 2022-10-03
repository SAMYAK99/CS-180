
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) 
{
        int i,j;
        vector<int> ans;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
}
int main()
{
    vector<int> vect{ 2,7,11,15 };
    int target = 9;
    vector<int> ans = twoSum(vect,target);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}