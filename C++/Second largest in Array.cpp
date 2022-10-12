#include<bits/stdc++.h>
using namespace std;

void secondLargest(int arr[] , int n)
{
	int res = -1;  //res store index of second largest
	int largest = 0; //index of largest element

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[largest]) {
			res = largest;
			largest = i;
		}

		else if (arr[i] < arr[largest]) {
			if (res == -1 or arr[i] > arr[res])
				res = i;
		}
	}
	if (res == -1)
		cout << "Array don't have second largest element.";
	else
		cout << "Second largest element is " << arr[res];
}

int main()
{

	int n; cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	secondLargest(arr , n);

	return 0;
}
