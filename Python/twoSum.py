# Link to question : https://leetcode.com/problems/two-sum/
# Solution :
# In Python 3:
class Solution:
  def twoSum(nums, target):
    for i in range(len(nums)):
      for j in range(i+1, len(nums)):
        sum = nums[i]+nums[j]
        if sum == target:
          return i, j
    return []