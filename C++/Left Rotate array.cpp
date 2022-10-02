/*
Left Rotate the array by 1

arr[] = {1, 2, 3, 4, 5}
o / p : {2, 3, 4, 5, 1}
*/

#include<bits/stdc++.h>
using namespace std;

void rotateleft(int arr[] , int n) {
	int temp = arr[0];

	for (int i = 1; i < n; i++) {
		arr[i - 1] = arr[i];
	}

	arr[n - 1] = temp;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{

	int arr[] = {1, 2, 3, 4, 5};
	rotateleft(arr, 5);
}

