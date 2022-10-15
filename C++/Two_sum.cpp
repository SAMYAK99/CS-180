#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if (m.find(nums[i]) == m.end()){
                m[nums[i]]=i;
            }
            if(m.find(target - nums[i])!=m.end()&& i!=m[target-nums[i]]){
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            //      m.put(nums[i],i);
        }
        return result;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       vector<int> nums = {2,7,11,15};
      int target = 9;
        Solution obj;
        cout<<obj.twoSum(nums, target)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
