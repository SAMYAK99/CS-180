#include <stdio.h>


int main()
 
{int i,j,m,l,k, n, o, p, q, r;

 
for(i=1;i<=5;i++)
 
{
 
for(j=5;j>=i;j--)
 
{ 
 
printf("*");
 
}
 
for(k=1;k<i;k++)
 
{
 
printf(" ");
 
}
 
for(l=1;l<i;l++)
 
{ 

printf(" ");
 
}
 
for(m=5;m>=i;m--)
 
{
 
printf("*");
 
}
 
printf("\n");
 
}

for(n=6;n<=10;n++)
 
{
 
for(o=6;o<=n;o++)
 
{ 
 
printf("*");
 
}
 
for(p=10;p>n;p--)
 
{
 
printf(" ");
 
}
 
for(q=10;q>n;q--)
 
{ 
 
printf(" ");
 
}
 
for(r=6;r<=n;r++)
 
{
 
printf("*");
 
}
 
printf("\n");
 
}
 
return 0;
 
}