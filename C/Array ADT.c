#include<stdio.h>
#include<stdlib.h>

struct array{
int*A;
int length;
};

struct array* Create_Array(int size)
{
    struct array* a;
    int i,j,n;
    a->A=(int*)malloc((sizeof(int))*size);
    a->length=size;
    printf("Enter elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&n);
        a->A[i]=n;
    }

    return a;

}
void Display(struct array*a)
{
    int i;
     for(i=0;i<a->length;i++)
    {
        printf("%d\t",a->A[i]);
    }
     printf("\n");
}

void insert(struct array*a, int index, int data)
{
    int i;
    if(index>=0&&index<=a->length)
        {
            for(i=(a->length);i>index;i--)
            {
                a->A[i]=a->A[i-1];
            }
            a->A[index]=data;
            a->length++;
        }
}

int Delete(struct array*a,int index)
{
    int i;
    if(index>=0&&index<=a->length)
        {
            int x;
            x=a->A[index];
            for(i=index+1;i<a->length;i++)
            {
                a->A[i-1]=a->A[i];
            }
            a->length--;
            return x;
        }
    return -1;
}
int Lsearch(struct array* a, int key)
{
    int i;
    //printf("%d",key);
    for(i=0;i<(a->length);i++)
    {
        if(a->A[i]==key)
        {
              printf("%d is at index %d",a->A[i],i);
              return i;
        }

    }
    printf("Not found\n");
    return -1;
}
int Bsearch(struct array* a, int key)
{
    int l=0,h,m;
    h=a->length;

    while(l<=h)
    {
        m=(l+h)/2;
        if(a->A[m]==key)
            {printf("\n%d is at index %d\n",key,m);
                return m;
            }
        else if(key<a->A[m])
            h=m-1;
        else
            l=m+1;
    }
    printf("Not found\n");
    return -1;
}
int RBsearch(struct array* a,int l,int h, int key)
{
    int m;
    if(l<=h)
    {
    m=(l+h)/2;
    if(a->A[m]==key)
        {printf("%d is at index %d\n",key,m);
        return m;
        }
    else if(key<a->A[m])
        return RBsearch(a,l,m-1,key);
    else
        return RBsearch(a,m+1,h,key);
    }
    printf("Not found\n");
    return -1;
}
struct array* Reverse1(struct array* a)
{
    int i=0,j=0;
    int *B;
    B=(int*)malloc(sizeof(int)*a->length);
    for(i=(a->length)-1,j=0;i>=0;i--,j++)
    {
        B[j]=a->A[i];
    }

    for(j=0;j<(a->length);j++)
    {
        a->A[j]=B[j];
    }

    return a;


}
struct array* Reverse2(struct array*a)
{
    int i,j,temp;
    for(i=0,j=a->length-1;i<j;i++,j--)
    {
        temp=a->A[i];
        a->A[i]=a->A[j];
        a->A[j]=temp;
    }
    return a;
}
int max(struct array*a)
{
    int max = a->A[0];
    int i;
    for(i=1;i<a->length;i++)
    {
        if(a->A[i]>max)
            max=a->A[i];
    }
    return max;
}
int min(struct array *a)
{
    int min = a->A[0];
    int i;
    for(i=1;i<a->length;i++)
    {
        if(a->A[i]<min)
            min=a->A[i];
    }
    return min;
}

int sum(struct array *a)
{
    int i,s=0;
    for(i=0;i<a->length;i++)
    {
        s+=a->A[i];
    }
    return s;
}

void rotateRight(struct array *a, int n)
{
    int i,j,k;
    int *b;
    b = (int*)malloc(a->length*sizeof(int));
    for(i=0;i<n;i++)
        b[i]=a->A[a->length-n+i];
    for(j=0;j<=a->length-n-1;j++)
        a->A[n+j]=a->A[j];
    for(k=0;k<n;k++)
        a->A[k]=b[k];
}


void main()
{
    int i,j,n;
    int key,bit;
    int x;
    struct array *a;
    int c;
    printf("\n**Please create an array first**\n");
    while(1)
    {


        printf("\nEnter choice: ");
        printf("\n1.Create Array\n2.Display Array\n3.Insert element at index\n4.Delete from index\n5.Perform Linear search\n6.Perform Binary search\n7.Perform Recursive Binary Search\n");
        printf("8.Largest element\n9.Smallest element\n10.Sum of elements\n");
        printf("11.Reverse the array\n12.Rotate Right\n13.EXIT\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter size of the array\n");
                scanf("%d",&n);
                printf("Entered size=%d\n",n);
                a = Create_Array(n);
                Display(a);
                break;
            }
            case 2:
                {
                    Display(a);
                    break;
                }
            case 3:
                {
                    int index,data;
                    printf("Enter index at which you want to insert: ");
                    scanf("%d",&index);
                    printf("\nEnter element you want to insert: ");
                    scanf("%d",&data);
                    insert(a,index,data);
                    break;
                }
            case 4:
                {
                    int index;
                    printf("Enter index from which you want to delete: ");
                    scanf("%d",&index);
                    printf("Deleted element: %d ",Delete(a,index));
                    break;
                }
            case 5:
                {

                    printf("\nEnter element to search: ");
                    scanf("%d",&key);
                    Lsearch(a,key);
                    break;
                }
            case 6:
                {

                    printf("\nEnter element to search: ");
                    scanf("%d",&key);
                    Bsearch(a,key);
                    break;
                }
            case 7:
                {

                    printf("\nEnter element to search: ");
                    scanf("%d",&key);
                    RBsearch(a,0,a->length,key);
                }
            case 8:
                {
                    printf("\nLargest element: %d",max(a));
                    break;
                }
            case 9:
                {
                    printf("\nSmallest element: %d",min(a));
                    break;
                }
            case 10:
                {
                    printf("\nSum of elements: %d",sum(a));
                    break;
                }
            case 11:
                {
                    Reverse2(a);
                    Display(a);
                    break;
                    Display(a);
                }
            case 12:
                {

                    printf("Rotate by: ");
                    scanf("%d",&bit);
                    rotateRight(a,bit);
                    break;
                    Display(a);
                }
            case 13:
                {
                    printf("\nThank You!!!");
					return 0;

                    break;
                }
            default:
					printf("\nEnter correct choice");

        }
    }








}
