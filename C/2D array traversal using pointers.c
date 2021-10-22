#include<stdio.h>
void traverse(int* arr,int n,int m)
{
    int shj,j;
    for(shj=0;shj<n;shj++)
    {
        for(j=0;j<m;j++)
        {
             printf("%d ",*((arr+shj*m)+j));
        }
    printf("\n");
    }
}
int main()
{
    int n=3,m=2;
    int arr[]={{1,2},
               {3,4},
               {5,6}};
    traverse((int*)arr,n,m);
    return 0;
}
