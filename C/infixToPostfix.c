#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char in_str[20], post_str[20];
int top;
int stack[20];
int pop();
int precedence(char symbol);
int isEmpty();
void InfixToPostfix();
int check_space(char symbol);
void push(long int symbol);

int main()
{
int count, length;
char temp;
top = -1;
printf("\nEnter a Infix Expression : ");
scanf("%s", in_str);
InfixToPostfix();
printf("\nThe Equivalent postfix expression will be : %s\n", post_str);
return 0;
}

void InfixToPostfix()
{
unsigned int count, temp = 0;
char next;
char symbol;
for(count = 0; count < strlen(in_str); count++)
{
    symbol = in_str[count]; 
    if(!check_space(symbol))
{
 switch(symbol)
  {
    case '(': push(symbol);
    break;
    case ')': while((next = pop()) != '(') 
                {
                post_str[temp++] = next;
                }
                break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^': while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)) 
                post_str[temp++] = pop();
                push(symbol);
                break;
    default:post_str[temp++] = symbol;
  }
 }
}
while(!isEmpty())
 {
  post_str[temp++] = pop();
 }
  post_str[temp] = '\0';
}

int precedence(char symbol)
{
 switch(symbol)
  {
   case '(': return 0;
   case '+':
   case '-':return 1;
   case '*':
   case '/':
   case '%':return 2;
   case '^': return 3;
   default: return 0;
  }
}

int check_space(char symbol)
{
if(symbol == '\t' || symbol == ' ' )
   {
    return 1;
   }
else
   {
    return 0;
   }
}

void push(long int symbol)
{
if(top > 20)
    {
    printf("Stack Overflow\n");
    exit(1);
    }
top = top + 1;
stack[top] = symbol; 
}

int isEmpty()
{
if(top == -1)
    {
    return 1;
    }
else
    {
    return 0;
    }
}

int pop()
{
if(isEmpty())
   { 
    printf("Stack is Empty\n");
    exit(1);
   }
return(stack[top--]); 
}
