#include <stdio.h>
int main()
{
  int row, c, n;
  printf("Enter the number of rows to print pyramid: \n");
  scanf("%d", &n);

  for (row = 1; row <= n; row++)
  {
    for (c = 1; c <= n-row; c++)
      printf(" ");

    for (c = 1; c <= 2*row - 1; c++)
      printf("$");

    printf("\n");
  }
  printf("\n ************Congragulations you have done it successfully****************");
  return 0;

}
