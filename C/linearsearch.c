#include <stdio.h>
int main()
{
   int arr[1000],n , element;
   printf("\n Enter the no. of Elements in array  ");
     scanf("%d",&n);
     
       for(int i=0;i<n;i++){
             scanf("%d",&arr[i]);
       }
      
      printf("\n Enter the element to be searched ");
             scanf("%d",&element);
     
    int flag =0 ; 
     int pos  ;

       for(int i = 0 ;i <n ; i++){
         if(arr[i]==element){
           flag =1 ; 
           pos = i+1 ; 
           break ; 
         }
      }
        
        if(flag == 1)
         printf("\n The element is found in %d postion" , pos);
         else
          printf("\n The element is found in not in the array");
          
     return 0;
}
