#include <iostream>

using namespace std;

void exchange(int a[], int i, int j, int d)
{
        int temp;
        if (d == (a[i] > a[j]))
        {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
        }
}
void merge(int a[], int beg, int c, int d)
{
        int k, i;
        if (c > 1) 
        {
                k = c / 2;
                for (i = beg; i < beg + k; i++)
                        exchange(a, i, i + k, d);
                merge(a, beg, k, d);
                merge(a, beg + k, k, d);
        }
}
void bitonicSort(int a[], int beg, int c, int d)
{
        int k;
        if (c > 1)
        {
                k = c / 2;
                bitonicSort(a, beg, k, 1);            // sort in ascending order  
                bitonicSort(a, beg + k, k, 0);        // sort in descending order  
                merge(a, beg, c, d);                  //merge the sequence in ascending order  
        }
}


void sort(int a[], int n, int order) 
{
        bitonicSort(a, 0, n, order);
}
void print(int a[], int n)            //function to print array elements  
{
        int i;
        for (i = 0; i < n; i++) 
        {
                cout << a[i] << " ";
        }
}

int main() 
{
        int a[]= {20, 60, 30, 70, 50, 10, 5, 40};
        int n = sizeof(a) / sizeof(a[0]);
        int order = 1; 
        
        cout << "Before sorting array elements are - \n";
        print(a, n);
        sort(a, n, order);
        cout << "\nAfter sorting array elements are - \n";
        print(a, n);
        return 0;
}
