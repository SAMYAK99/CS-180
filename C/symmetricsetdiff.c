// WAP To Create two sets and perform the  Symmeteric set difference operation 
#include<stdio.h>
int main (){
    int n,m , set1[100] , set2[100];
  

   printf("\n Enter the  Elements  of SET A  ");
     scanf("%d",&n);
      for(int i=0;i<n;i++){
             scanf("%d",&set1[i]);
       }

     printf("\n Enter the  Elements  of SET B  ");
     scanf("%d",&m);
         for(int i=0;i<m;i++){
             scanf("%d",&set2[i]);
       }

     int i = 0  , j = 0 , c[100]  , k = 0 ; 
     printf("\n Symmetric Set Difference of two sets are ") ; 
      while (i < n && j < m) { 
        if (set1[i] < set2[j]) { 
           printf("%d ", set1[i]);
            i++; 
        } 
        else if (set2[j] < set1[i]) { 
           printf("%d ", set2[j]);
            j++; 
        } 
        else{ 
            i++; 
            j++; 
        } 
    } 

  return  0 ; 
}
