#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
#define MAX 10000

int stack[MAX], top = -1;

void push(int item) 
{ 
    if (top == MAX - 1){
        printf("Max Size reached\n");
        return; 
    }

    stack[++top] = item; 
}

int pop() 
{ 
    if (top==-1) 
        return INT_MIN; 
    return stack[top--]; 
}

int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

int getPostfix(char *expression) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        else if (expression[i] == '(') 
            push(expression[i]); 

        else if (expression[i] == ')') 
        { 
            while (top!=-1 && stack[top] != '(') 
                expression[++j] = pop(stack); 
            if (top!=-1 && stack[top] != '(') 
                return -1;              
            else
                pop(); 
        } 
        else
        { 
            while (top!=-1 && precedence(expression[i]) <= precedence(stack[top]))
                expression[++j] = pop(); 
            push(expression[i]); 
        } 

    } 
    while (top!=-1) 
        expression[++j] = pop(); 

    expression[++j] = '\0'; 
    
}

int main()
{    
    printf("The infix is: ");

    char expression[] = "((a/b)+c)-(d+(e*f))"; 
    printf("%s\n",expression);
    getPostfix(expression); 

    printf("The postfix is: ");
    printf("%s\n",expression);

    return 0; 
}

/*
OUTPUT:
The infix is: ((a/b)+c)-(d+(e*f))
The postfix is: ab/c+def*+-
*/