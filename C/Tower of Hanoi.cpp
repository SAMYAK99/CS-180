#include<stdio.h>
void hani(int,char,char,char);
int main()
{
	int n;
	char a,b,c;
	printf("input the number of disks  ");
	scanf("%d",&n);
	printf("tower of hanoi for %d disc",n);
	hani(n,'a','b','c');
}
void hani(int n,char beg, char aux, char end)
{
	if (n==1)
	{
		printf("\nmove disc from %c to %c",beg,end);
	}
	else
	{
		hani(n-1,beg,end,aux);
		hani(1,beg,aux,end);
		hani(n-1,aux,beg,end);
	}
}
