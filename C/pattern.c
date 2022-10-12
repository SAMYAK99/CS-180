//Github username: Mehnaz14
// Aim: This is a pattern of half pyramid using c language
// Date: 8.10.22
// So in this case :
//Time complexity:0(n^2).
//Space complexity:0(1).

// start coding
#include <stdio.h>
int main() {
   int i, j, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i) {
      for (j = 1; j <= i; ++j) {
         printf("* ");
      }
      printf("\n");
   }
   return 0;
}

//We are printing the no of'*' for each respective rows like n*(n-1)*(n-2)....,so Time complexity is 0(n^2).
//We are using constant space,so Space complexity is 0(1).