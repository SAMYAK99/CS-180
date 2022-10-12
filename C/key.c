/*WAP in C to count the number of times a given key occurs in a linked list. 
Also, find the percentage of the occurrence otherwise display an appropriate message.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
};

struct node *head,*temp,*newnode;
int count=0;

void create();
void display();
void occurence(int);

int main()
{
	int n;
	create();
	display();
	printf("\n\nEnter a number to get the occurence: ");
	scanf("%d", &n);
	occurence(n);
}

void create()
{
	char flag;
	printf("Enter the elements of the Linked List:\n\n");
	do{
		newnode = (struct node *)malloc(sizeof(struct node));
		if(head==NULL){
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			head=newnode;
			temp=newnode;
			temp->next=NULL;
			temp->prev=NULL;
			count++;
		}

		else
        {	
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
			temp->next=NULL;
			
			count++;
		}

		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&flag);
		getchar();
		
	}
    while(flag='y' && flag!='n');
}

void display()
{
	printf("\nThe List is Diplaying: \n");
	temp=head;
	while(temp!=NULL)
    {
		printf(" %d ", temp->data);
		temp=temp->next;
	}	
}

void occurence(int n)
{
	temp=head;
	float counter;
	while(temp!=NULL)
    {
		if(temp->data==n)
        {
			counter++;
		}
		temp=temp->next;
	}

	if(counter!=0)
		printf("\nPercentage occurence of %d is %.2f", n,(counter/count)*100);
	else
		printf("\nThe Entered element is not found in the list!");
}
