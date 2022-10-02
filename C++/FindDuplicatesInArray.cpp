input =[2,5,9,6,9,3,8,9,7,1]
output=[2,5,9,6,3,8,7,1]
/*Intuition 1:*/
/*  Basic intuition that comes to our mind is to sort the array and after sorting we can simply traverse to check the presence of duplicates*/
/*This approach will require the complexity of O(nlogn) but it will distort the array and the space complexity required will be O(1)*/


/* Intuition 2  : */ 
/* Inorder to reduce the time complexity we will have to adjust with the space complexity and that can be done with the help of maintaining a frequency array which
will be initially marked with all zero's and then we can traverse and add 1 whenever we find that number if that one gets updated to 2 then those are the duplicated */
/* Though the time complexity is O(N) but the space complexity is also O(N) */

/* Can we come up with a solution which will  utilize O(N) time complexity and O(1) space complexity */
/* The Tortoise and the Hare (Floyd’s Algorithm) */
/* input =[2,5,9,6,9,3,8,9,7,1]
   output=[2,5,9,6,3,8,7,1] 
1) place Fast and slow pointer at the start.
2) Move fast by two steps and slow by one.
3) At one point the will form a cycle since duplicates are present.
4) Once the duplicates are found you can simply place the fast pointer at the start and iterate again one step at a time for both fast and slow pointer.
5) Do this till fast != slow .*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
    }
};

/*https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare*/
