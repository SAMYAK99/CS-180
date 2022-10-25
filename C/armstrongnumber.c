#include<stdio.h>
#include<math.h>
int main()
{
	int n,d,s=0,num=0,c=0,num1=0,i;
	printf("enter the number");
	scanf("%d",&n);
	num=n;
	while(n!=0)
	{
		d=n%10;
		c++;
		n=n/10;
	}
	num1=num;
	while(num!=0)
	{
		i=num%10;
		s=s+pow(i,c);
		num=num/10;
	}
	if(s==num1)
	printf("armstrong");
	else
	printf("not armstrong");
}
