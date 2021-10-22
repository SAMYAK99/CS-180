#include<stdio.h>
int main()
{
	int a[10][10],t[10][10];
	int rch,c,i,j;
	scanf("%d%d",&rch,&c);
	for (i=0;i<rch;i++)
	{
		for(j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	for(i=0;i<rch;i++)
	{
		for(j=0;j<c;j++)
	printf("%d",t[i][j]);
}
}
