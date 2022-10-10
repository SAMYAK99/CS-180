#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);

    int LinearSearch(int key);
    int BinarySearch(int key);
    //int RBinSearch(int a[],int l,int h,int key);
    int Get(int index);
    void Set(int index, int x);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void Reverse2();
void InsertSort(int x);
int isSorted();
void Rearrange();
Array* Merge(Array *arr2);
Array* Union(Array *arr2);
Array* Intersection(Array *arr2);
Array* Difference(Array *arr2);
};

void Array::Display()
{
    int i;
    printf("\nElements are:\n");
    for(i=0;i<length;i++)
        printf("%d ",A[i]);
}

void Array::Append(int x)
{
    if(length < size)
        A[length++] = x;


}

void Array::Insert(int index, int x)
{
    int i;

    if(index>=0 && index<=length)
    {
        for(i=length;i>index;i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }

}

int Array::Delete(int index)
{
    int x=0;
    int i;
    if(index>=0 && index<length)
    {
        x = A[index];

        for(i=index;i<length-1;i++)
            A[i] = A[i+1];

           length--;
            return x;
    }

}



void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key)
{
    int i;

    for(i=0;i<length;i++)
    {
        if(key == A[i])
            {
                swap(&A[i],&A[0]);

                return i;
            }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h=mid-1;
        else
            l = mid+1;
    }
    return -1;

}

int RBinSearch(int a[],int l,int h,int key)
{
    int mid;

    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);

    }
}

int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;

}

void Array::Set(int index, int x)
{
    if(index>=0 && index<length)
        A[index] = x;

}

int Array::Max()
{
    int max = A[0];
    int i;
    for(i=0;i<length;i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    int i;
    for(i=0;i<length;i++)
    {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int s=0;
    int i;

    for(i=0;i<length;i++)
        s += A[i];
    return s;
}

float Array::Avg()
{
    return (float)(Sum(arr)/length);
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B = (int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length == arr->size)
        return;

        while(i>=0 && arr->A[i] > x)
        {
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1] = x;
        arr->length++;

}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
        {
            if(arr.A[i]>arr.A[i+1])
                return 0;
        }
        return 1;

}

void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j = arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>=0)
            j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];

    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}


struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])                   //unequal hai to dono ko add kro C array me
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];  //equal hai to kissi ek ko add kro C array me
            j++;
        }


    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
           i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j])                               //if both are equal copy any one of them into C array
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }


    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])              //unequal hai to use add kro C array me A se  A-B me
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else                                   //dono equal hai to ++ karke ignore kro
        {
            i++;
            j++;
        }


    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int main()
{
    struct Array arr1;
    int ch,x,index;

    printf("Enter size of Array");
    scanf("%d",&arr1.size);
    arr1.A = (int *)malloc(arr1.size*sizeof(int));

    do
    {
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1: printf("Enter an element and index");
        scanf("%d%d",&x,&index);
        Insert(&arr1,index,x);
        break;
        case 2: printf("Enter index");
            scanf("%d",&index);
            x = Delete(&arr1,index);
            printf("Deleted element is %d\n",x);
            break;
        case 3: printf("Enter element to search");
            scanf("%d",x);
            index = LinearSearch(&arr1,x);
            printf("Element index %d",index);
            break;
        case 4: printf("Sum is %d\n",Sum(arr1));
            break;
        case 5: Display(arr1);

    }
    } while(ch<6);
        return 0;
}

