#include <stdio.h>

#define SIZE 20
int array[SIZE];  
int top1 = -1;
int top2 = SIZE;

void push1(int data) 
{
        if (top1 < top2 - 1)
        {
                top1++;
                array[top1] = data;
        } 
        
        else
        {
                printf("Stack is full");
        }
}

void push2(int data)
{
        if (top1 < top2 - 1)
        {
                top2--;
                array[top2] = data;
        }
        else
        {
                printf("Stack is full..\n");
        }
}

void pop1() 
{
        if (top1 >= 0) 
        {
                int popped_element = array[top1];
                top1--;

                printf("%d is being popped from Stack 1\n", popped_element);
        }
        else
        {
                printf("Stack is Empty \n");
        }
}

void pop2()
{
        if (top2 < SIZE) 
        {
                int popped_element = array[top2];
                top2--;

                printf("%d is being popped from Stack 1\n", popped_element);
        } 
        else
        {
                printf("Stack is Empty!\n");
        }
}

void display_stack1()
{
        int i;
        for (i = top1; i >= 0; --i)
        {
                printf("%d ", array[i]);
        }
        printf("\n");
}
void display_stack2()
{
        int i;
        for (i = top2; i < SIZE; ++i) 
        {
                printf("%d ", array[i]);
        }
        printf("\n");
}

int main() 
{
        int ar[SIZE];
        int i;
        int num_of_ele;

        printf("We can push a total of 20 values\n");

        for (i = 1; i <= 10; ++i) 
        {
                push1(i);
                printf("Value Pushed in Stack 1 is %d\n", i);
        }
       
        for (i = 11; i <= 20; ++i) 
        {
                push2(i);
                printf("Value Pushed in Stack 2 is %d\n", i);
        }

        display_stack1();
        display_stack2();

        printf("Pushing Value in Stack 1 is %d\n", 11);
        push1(11);

        num_of_ele = top1 + 1;
        while (num_of_ele) 
        {
                pop1();
                --num_of_ele;
        }

        pop1();

        return 0;
}
