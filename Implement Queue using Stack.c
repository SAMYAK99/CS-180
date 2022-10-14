#include<stdio.h>

#define N 5
int stack1[5], stack2[5];  
int top1 = -1, top2 = -1;
int count = 0;
 
void push1(int data) 
{   
        if (top1 == N - 1) 
        {
                printf("\n Stack is overflow...");
        } else {
                top1++;  
                stack1[top1] = data; 
                }
}
  
int pop1()
{    
        if (top1 == -1)
        {
                printf("\nStack is empty..");
        }
        else
        {
                int a = stack1[top1]; 
                top1--; 
                return a;
        }
}
void push2(int x)
{
        if (top2 == N - 1) 
        {
                printf("\nStack is full..");
        }
        else 
        {
                top2++;
                stack2[top2] = x; 
        }
}

int pop2()
{
        int element = stack2[top2];  
        top2--;   
        return element;
}
void enqueue(int x)
{
        push1(x);
        count++;
}
void dequeue()
{
        if ((top1 == -1) && (top2 == -1))
        {
                printf("\nQueue is empty");
        } 
        else
        {
                for (int i = 0; i < count; i++)
                {
                        int element = pop1();
                        push2(element);
                }
                int b = pop2();
                printf("\nThe dequeued element is %d", b);
                printf("\n");
                count--;
                for (int i = 0; i < count; i++)
                {
                        int a = pop2();
                        push1(a);
                }
        }
}
void display() 
{
        for (int i = 0; i <= top1; i++)
        {
                printf("%d , ", stack1[i]);
        }
}
void main()
{
        enqueue(10);
        enqueue(20);
        enqueue(30);
        dequeue();
        enqueue(50);
        display();
}
