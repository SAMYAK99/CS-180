/*There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function,
nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity..*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int util(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1, m;

        while (l < h)
        {

            if (nums[l] < nums[h])
                return l;
            m = l + (h - l) / 2;
            if (nums[l] <= nums[m])
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
    int solve(vector<int> &nums, int l, int h, int target)
    {

        int m;
        while (l <= h)
        {

            m = l + (h - l) / 2;
            if (nums[m] == target)
                return m;
            if (target > nums[m])
                l = m + 1;
            else
                h = m - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        // if(n==1 && nums[0]==target) return 0;
        int l = 0, h = n - 1, m;

        int piv = util(nums);

        if (nums[piv] <= target && target <= nums[h])
            return solve(nums, piv, h, target);
        else
            return solve(nums, l, piv - 1, target);
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution obj;
    cout << obj.search(nums, target);

    return 0;
}
