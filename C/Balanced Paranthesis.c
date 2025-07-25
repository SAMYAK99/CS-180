//Balanced Paranthesis
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char data;
    struct Node* next;
};
struct Node* top=NULL;
void Push(char ch)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ch;
    new->next=top;
    top=new;
}
char Pop()
{
    if(top==NULL){
        return '\0';
    }
    struct Node* temp=top;
    char ch=temp->data;
    top=top->next;
    free(temp);
    return ch;
}
int isEmpty(){
    return top==NULL;
}
int isBalanced(char* exp)
{
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('|| exp[i]=='{'||exp[i]=='['){
            Push(exp[i]);//I am using Push, only for open brackets
        }
        else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']'){
            if(isEmpty()){//If the stack is empty and you enter closing brackets first only, definitely it's not balanced
                return 0;
            }
            char topChar=Pop();
            if((exp[i]==')' && topChar!='(') ||(exp[i]=='}'&&topChar!='{')||(exp[i]==']'&& topChar!='[')){
                return 0;/*Note that, here, topChar sees only about the braces, because my Push function is applied
                only for braces, so Pop will return only the braces*/
            }
        }
    }
    return isEmpty();
}
int main()
{
    char exp[100];
    printf("Enter an expression:\n");
    scanf("%s",exp);
    if(isBalanced(exp)){
        printf("Paranthesis are balanced");
    }
    else
        printf("Paranthesis are not balanced");
    return 0;
}