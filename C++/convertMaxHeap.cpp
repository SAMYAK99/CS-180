#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int arr[], int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < N && arr[l] > arr[i])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, N);
    }
}

void convertMaxHeap(int arr[], int N)
{
    for (int i = (N - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Min Heap array : ");
    printArray(arr, N);

    convertMaxHeap(arr, N);

    printf("\nMax Heap array : ");
    printArray(arr, N);

    return 0;
}
