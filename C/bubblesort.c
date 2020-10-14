#include <stdio.h>

int main()
{
   int arr[1000],n , element;
  
   printf("\n Enter the no. of Elements in array  ");
     scanf("%d",&n);
     
       for(int i=0;i<n;i++){
             scanf("%d",&arr[i]);
       }
      
      printf("\n Sorted Array : ");
            int i,j , temp = 0 ;

       for( i = 0 ; i<n-1 ; i++){ 
         for( j=0 ; j<n-i-1; j++){
                if (arr[j] > arr[j+1]) {
      
                  int temp = arr[i]; 
                 arr[i]= arr[j]; 
                   arr[j]=temp  ; 
                }
         }
      }
        for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
       

    return 0;
}
