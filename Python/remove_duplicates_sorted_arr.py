def removeDuplicates(arr):
  ptr = 0
  for i in range(len(arr)):
    if arr[i] != arr[ptr]:
      ptr += 1
      arr[i], arr[ptr] = arr[ptr], arr[i]

  return ptr + 1

def removeDuplicates2(nums):
  temp = [nums[0]]
  for num in nums:
    if num != temp[-1]:
      temp.append(num)
  for i in range(len(temp)):
    nums[i] = temp[i]
  return len(temp)

arr = [1, 2, 2, 2, 3, 4, 4]

print(removeDuplicates2(arr))

print(arr)