#include<stdio.h>
int main()
{
	int n,i,j,arr[50],temp;
	printf("Enter size of an array : ");
	scanf("%d",&n);
	printf("Enter elements of an array : ");
	for(i=0; i<=n-1; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0; i<=n-1; i++)
	{
		for(j=i+1; j<=n-1; j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nEnter value of k: ");
	scanf("%d",&i);
	printf("%dth smallest element is %d",i,arr[i-1]);
	printf("\n%dth greatest element is %d",i,arr[n-i]);
	return 0;
}