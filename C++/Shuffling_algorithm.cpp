#include <iostream>

using namespace std;

// Function for shuffling an Array in a Single Pass
void shuffleArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j = rand()%(i+1); // getting a random index from right-side part
        swap(arr[i],arr[j]); // swapping with the left-part
    }
    //Printing the Array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(NULL));
  
    int arr[6] = {1,5,6,2,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    shuffleArray(arr,n);
    
    return 0;
}
