int findMajorityElementNaive(int nums[], int n)
{
    // check whether `nums[i]` is a majority element or not
    for (int i = 0; n && i <= n/2; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
 
        if (count > n/2) {
            return nums[i];
        }
    }
 
    return -1;
}
