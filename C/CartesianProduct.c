// Cartesian product of 2 sets in c

#include <stdio.h> 

int main() 
{ 
  	
	int arr1[] = { 1, 2, 3 }; // first set 
	int arr2[] = { 4, 5, 6 }; // second set 
   int n1 =3, n2 =3 ; 

  	for (int i = 0; i < n1; i++) 
		 for (int j = 0; j < n2; j++) 
			printf("{%d, %d}, ", arr1[i], arr2[j]); 
	return 0; 
} 
