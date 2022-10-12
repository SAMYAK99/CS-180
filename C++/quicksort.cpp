#include<iostream>

using namespace std;
int partition(int a[],int,int);
int partition(int a[],int low,int high){
    int pivot=a[high];
    int pindex=low;
    for(int i=low;i<high;i++){
        if(a[i]<=pivot){
            swap(a[pindex],a[i]);
            pindex++;}
        }
        swap(a[pindex],a[high]);
        return pindex;

    }

int quicksort(int a[], int m, int n)
{
    int index;
    if(m>=n)
        return 0;
    {
        index = partition(a,m,n);
        quicksort(a, m, index-1);
        quicksort(a, index+1, n);
    }
}

int main()
{
    int a[99];
    int n;
    cout<<"enter the no of elements u want to enter"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int i;
    quicksort(a,0,n-1);
    cout <<"After Sorting" << endl;
    for(i=0;i<n;i++)
        cout <<a[i] <<endl;
}
