/*This program has 4 approaches*/
We can proceed with a brute force approach and then can improve on space and time complexity.
1) Example:
Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
/*step 1: 
use sorting 
Sorting will take Time Complexity: O(nLogn)
If you use merge sort then you will require extra space so it will be o(N).*/
/*Step 2:
Use frequency array and mark the visited numbers in the frequency array.
Time Complexity: O(n)
Auxiliary Space: O(n) */
/*Step 3: 
Here you can use two equation 
1: Sum of elements till N
2:Sum of elements till N^2
 Let us write code for this and analayze if its the best or can we do better ?
   
vector<int>repeatedNumber(const vector<int> &A) { 
    long long int len = A.size(); 
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; 
    long long int missingNumber=0, repeating=0; 
      
    for(int i=0;i<A.size(); i++){ 
       Sum_N -= (long long int)A[i]; 
       Sum_NSq -= (long long int)A[i]*(long long int)A[i]; 
    } 
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; 
    repeating= missingNumber - Sum_N; 
    vector <int> ans; 
    ans.push_back(repeating); 
    ans.push_back(missingNumber); 
    return ans; 
      
}
/*This code snippet involves the use of long long because of the squaring part.*/
/*Time Complexity: O(n)*/

*/We can improve further with the help of magical XOR operator.*/
/* This solution can be pictured in the form of seperation numbers in two buckets,one bucket which has repeating number and the other one which has missing no*/





void getTwoElements(int arr[], int n, 
                    int* x, int* y) 
{ 
    
    int xor1; 
  
    
  
    int i; 
    *x = 0; 
    *y = 0; 
  
    xor1 = arr[0]; 

    for (i = 1; i < n; i++) 
        xor1 = xor1 ^ arr[i]; 
  
   
    for (i = 1; i <= n; i++) 
        xor1 = xor1 ^ i; 
  

    set_bit_no = xor1 & ~(xor1 - 1); //setting the rightmost bit  
  

    for (i = 0; i < n; i++) { 
        if (arr[i] & set_bit_no) 
           //as mentioned picture this as bucket one 
            *x = *x ^ arr[i]; 
  
        else
             //as mentioned picture this as bucket two
            *y = *y ^ arr[i]; 
    } 
    for (i = 1; i <= n; i++) { 
        if (i & set_bit_no) 
          //as mentioned picture this as bucket one 
            *x = *x ^ i; 
  
        else
             //as mentioned picture this as bucket two
            *y = *y ^ i; 
    } 
  
    /* *x and *y hold the desired 
        output elements */
} 



