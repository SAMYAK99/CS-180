#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdbool.h>

int size = 8;
int intArray[8];
int top = -1;

int pop()
{
        return intArray[top--];
}

int peek()
{
        return intArray[top];
}

bool isFull() 
{
        return (top == size - 1);
}

bool isEmpty() 
{
        return (top == -1);
}

void push(int data)
{
        if (!isFull())
        {
                intArray[++top] = data;
        }
        else
        {
                printf("Cannot add data. Stack is full.\n");
        }
}
main()
{
        push(3);
        push(5);
        push(9);
        push(1);
        push(12);
        push(15);

        printf("Element at top of the stack: %d\n", peek());
        printf("Elements: \n");

        while (!isEmpty()) 
        {
                int data = pop();
                printf("%d\n", data);
        }
        printf("Stack full: %s\n", isFull() ? "true" : "false");
        printf("Stack empty: %s\n", isEmpty() ? "true" : "false");
}
