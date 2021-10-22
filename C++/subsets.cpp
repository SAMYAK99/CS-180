//link to problem-https://leetcode.com/problems/subsets/


class Solution:
 def subsets(self, nums: List[int]) -> List[List[int]]:
        
        res = []
		
        
        def solve(v = [], ind = 0):
            
            if ind == len(nums):
                res.append(v)
                return
            
            solve(v + [nums[ind]], ind + 1)  # pick
            solve(v, ind + 1)  # non-pick
        
        solve()
        return res
