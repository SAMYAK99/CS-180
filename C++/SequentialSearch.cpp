#include<stdio.h>
int sequentialSearch(int x[],int lowerBound,int upperBound,int lookFor)
{ int y;
y=lowerBound;
while(y<=upperBound)
{ if(x[y]==lookFor) return y;
y++;
}
return -1;
} int main()
{ int x[10],y,lookFor,foundAt;
for(y=0;y<=9;y++)
{
printf("Enter a number");
scanf("%d",&x[y]);
}
printf("Search what : ");
scanf("%d",&lookFor);
foundAt=sequentialSearch(x,0,9,lookFor);
if(foundAt==-1) printf("%d not found",lookFor);
else printf("%d found at index %d",lookFor,foundAt);
}