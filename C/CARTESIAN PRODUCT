
#include <stdio.h>
#include <conio.h>
int main()
{
    int a[50],b[50],c[50],i,m,n,j,k;
    printf("Enter the number of elements in Set-1-->\n");
    scanf("%d",&m);
    printf("elements of Set-1-->\n");
    for (i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("Enter the number of elements in Set-2-->\n");
    scanf("%d",&n);
    printf("elements of Set-2-->\n");
    for (i=0;i<n;i++)
    scanf("%d",&b[i]);
    printf("\nElement of Set-1 are:\n");
    for(i=0;i<m;i++)
    printf("%d\t",a[i]);
    printf("\nElement of Set-2 are:\n");
    for(i=0;i<n;i++)
    printf("%d\t",b[i]);
    printf("\nCartesian Products is:\n");
    printf("{");
    for(i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("(%d,%d)",a[i],b[j]);
            printf(",");
        }
    }
    printf("}");
}
