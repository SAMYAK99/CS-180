#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void selectionSort(int *,int,int);
int main()
{
int *array,e,size,i;
printf("Enter size of Array: ");
scanf("%d",&size);
array=(int *)malloc(sizeof(int)*size);
printf("Enter elements of array to be sorted:\n");
for(e=0;e<=size-1;e++) 
{
scanf("%d",&i);
array[e]=i;
}
selectionSort(array,0,size-1);
printf("Sorted array:\n");
for(e=0;e<=size-1;e++) printf("%d\n",array[e]);
free(array);
return 0;
}
void selectionSort(int *x,int lb,int ub)
{
int e,f,g,si;
e=lb;
while(e<=ub-1)
{
si=e;
f=e+1;
while(f<=ub)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[e];
x[e]=x[si];
x[si]=g;
e++;
}
}