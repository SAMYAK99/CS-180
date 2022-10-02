#include<stdio.h>
int main()
{
	int arr[10],i,pos,num,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
scanf("%d",&pos);
scanf("%d",&num);
for(i=n-1;i>=pos-1;i--)
{
arr[i+1]=arr[i];	
}	
arr[pos-1]=num;

for(i=0;i<n;i++)
{
	printf("%d",arr[i]);
}
return 0;
}
