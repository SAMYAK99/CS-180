/* we are finding odd-even 
   for two numbers using bit manipulation 2nd method
*/

#include<stdio.h>

void main()
{
    int arr[]={10,16};
    int c;
    for(int i=0;i<=(sizeof(arr)/sizeof(int));i++)
    {
        c= arr[i]&1 ;
        if(arr[i]==c)
        {
            printf("\nThe number %d is even",arr[i]);

        }
        else
        {
            printf("\nThe number %d is odd",arr[i]);
        }
        
    }
}