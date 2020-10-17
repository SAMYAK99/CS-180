// C program to illustrate 
// Menu-Driven program 
// using Switch-case 

#include <stdio.h> 
int input(); 
void output(float); 
int main() 
{ 
	float result; 
	int choice, num; 
	printf("Press 1 to calculate area of circle\n"); 
	printf("Press 2 to calculate area of square\n"); 
	printf("Press 3 to calculate area of sphere\n"); 
	printf("Enter your choice:\n"); 
	choice = input(); 
	
	switch (choice) { 
	case 1: { 
		printf("Enter radius:\n"); 
		num = input(); 
		result = 3.14 * num * num; 
		printf("Area of sphere="); 
		output(result); 
		break; 
	} 
	case 2: { 
		printf("Enter side of square:\n"); 
		num = input(); 
		result = num * num; 
		printf("Area of square="); 
		output(result); 
		break; 
	} 
	case 3: { 
		printf("Enter radius:\n"); 
		num = input(); 
		result = 4 * (3.14 * num * num); 
		printf("Area of sphere="); 
		output(result); 
		break; 
	} 
	default: 
		printf("wrong Input\n"); 
	} 
	return 0; 
} 
int input() 
{ 
	int number; 
	scanf("%d", &number); 
	return (number); 
} 

void output(float number) 
{ 
	printf("%f", number); 
} 
