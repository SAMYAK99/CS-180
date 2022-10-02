#include <stdio.h>

int main()
{
   int arr[1000],n , element;

   

     printf("\n Enter the  Size of array  ");
     scanf("%d",&n);

     printf(" Enter the  Elements of array  ");
       for(int i=0;i<n;i++){
             scanf("%d",&arr[i]);
       }
      
      printf(" Sorted Array : ");
            int key; 
        for (int i = 1; i < n; i++) { 
           key = arr[i]; 
            int j = i - 1; 
        while (int j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j -= 1; 
        } 
        arr[j + 1] = key; 
    } 

      for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    
    return 0;
}
