#include<stdio.h>
#include<conio.h>
typedef struct node
{
	int type;
	void *data;
	struct node *next;
}node;
node *getnode(void *p,int type)
{
	node *nn;
	nn=(node *)malloc(sizeof (node));
	nn->data=p;
	nn->next=NULL;
	return nn;
}
void insert_beg(node**s)
{
	node *nn;
	void *p;
	int x,c;
	float y;
	char z;
	printf("\n1 integer \n2 float\n3 characterf");
	printf("\n what type of data you want to enter");
	scanf("%d",&c);
	printf("enter data");
	if(c==1)
	{
		scanf(" %d ",&x);
		p=&x;
	}
	else if(c==2)
	{
		scanf(" %f ",&y);
		p=&y;
	}
	else if(c==3)
	{
		scanf(" %c ",&z);
		p=&z;
	}
	nn=getnode(p,c);
	if(*s==NULL)
	{
		*s=nn;
	}
	else
	{
		nn->next=*s;
		*s=nn;
	}
}
void display(node *start)
{
	node *p=start;
	while(p!=NULL)
	{
		if(p->type==1)
		printf(" %d ",*((int*)p->data));
		else if(p->type==2)
		printf(" %f ",*((float*)p->data));
		else if(p->type==3)
		printf(" %c ",*((char*)p->data));
		p=p->next;
	}
}
void main()
{
	int ch;
	node *start=NULL;
	clrscr();
	do
	{
		printf("\n enter menu ");
		printf("\n1 insertion \n2 display\n3 exit");
		printf("\n enter the choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_beg(&start);
				break;
			case 2: display(start);
				break;
			case 3: exit(0);

		}
	}while(1);
	getch();
}


