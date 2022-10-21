// C program to print square inside
// a square pattern
#include <stdio.h>
void printPattern(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		
		for (j = 1; j <= n; j++)
    {
			if ((i == 1 || i == n || j == 1 || j == n) ||
				(i >= 3 && i <= n - 2 && j >= 3 && j <= n - 2) &&
				(i == 3 || i == n - 2 || j == 3 || j == n - 2))
			{
		
				printf("*");
			}
			else
			{
				
				printf(" ");
			}
		}
	
		printf("\n");
	}
}

// Driver Code
int main()
{
	int n = 9;
	printPattern(n);
	return 0;
}
