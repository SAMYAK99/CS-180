class ArrayRotate
{
void leftRotate(int a[],int d,int n)
{
for(int i=0;i<d;i++)
{
leftRotateByOne(a,n);
}
}
void leftRotateByOne(int a[],int n)
{
int i,temp;
temp=a[0];
for(i=0;i<n-1;i++)
{
a[i]=a[i+1];
}
a[i]=temp;
}

void print(int a[],int n)
{
for(int i=0;i<n;i++)
{
System.out.print(a[i]+"  ");
}
}

public static void main(String args[])
{
ArrayRotate array=new ArrayRotate();
int a[]={2,3,4,5,6,7};
int d=2;
int n=a.length;
array.leftRotate(a,d,n);
array.print(a,n);
}
}