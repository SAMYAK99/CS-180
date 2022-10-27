class Solution {
    public int search(int[] nums, int target) {
int num1=pivot(nums);//finding pivot in the array
if(num1==-1){
return binarysearch(nums,target,0,nums.length-1);
}
if(nums[num1]==target){
return num1;
}
if(target>=nums[0]){
return binarysearch(nums,target,0,num1-1);
}
return binarysearch(nums,target,num1+1,nums.length-1);
}
public static int pivot(int []nums){
int start=0;
int end=nums.length-1;
while(start<=end){
int mid=start+((end-start)/2);
if(mid<end && nums[mid]>nums[mid+1]){
return mid;
}
if(mid>start && nums[mid]<nums[mid-1]){
return mid-1;
}
if( nums[start]>=nums[mid]){
end=mid-1;
}
else {
start=mid+1;
}
}
return -1;
}
public static int binarysearch(int[]nums,int target,int start,int end){
while(start<=end){
int mid=start+((end-start)/2);
if(nums[mid]<target){
start=mid+1;
}
else if(nums[mid]>target){
end=mid-1;
}
else{
return mid;
}
}
return -1;
}
}
