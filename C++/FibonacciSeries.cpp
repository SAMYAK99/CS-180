 #include<bits/stdc++.h> 
using namespace std; 

int fib(int n) 
{ 
    //fibonacci number for n less then or equal to 1 is always 1
	if (n <= 1) 
		return n; 
	
    return fib(n-1) + fib(n-2); 
} 

int main () 
{ 
	int n = 9; 
	
    cout << fib(n); 
	
    getchar(); 
	return 0; 
} 

