/* Program to print first n prime number */
#include<stdio.h>
int main()
{
	int i=2,j,n,flag,count=1;
	printf("How many prime number you want to enter : ");
	scanf("%d",&n);
	while(count<=n)
	{
			flag=0;
			for(j=2; j<=i/2; j++)
			{
				if(i%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0) 
			{
				printf("%d ",i);
				count++;
			}
			i++;
	}
	return 0;
}