#include<iostream>
#include<conio.h>
using namespace std;

void SortCountList();

class Node
{
public:
	char ch;
	int count;
	Node *next,*left;
};
Node *count_head=NULL,*TreeHead;

Node* create_node(char c)
{
	Node *temp = new Node();
	temp->ch=c;
	temp->count=1;
	temp->next=NULL;
	temp->left=NULL;
	return temp;
}

void count_frequency(string str)
{
	for(int i=0;i<str.length();i++)	
	{
		if(count_head==NULL)
		{	count_head = create_node(str[i]);	}
		else{
			Node *ptr=count_head;
			while(1)		
			{
				if(str[i] == ptr->ch)
				{	ptr->count++;	break;		}
				else if(ptr->next == NULL)
					{	ptr->next = create_node(str[i]);		break;	}
				else
					{	ptr = ptr->next;	}
			}
		}
	}
	
	SortCountList();

	Node *pt=count_head;
	while(1)
	{	cout<<pt->ch<<" = "<<pt->count<<"     ";
		if(pt->next != NULL)
			pt=pt->next;
		else
			break;
	}
	cout<<"\n\n";	
}

Node* MakeTree()
{
	Node *Pleft,*Pright,*Ptr,*sum;
	Pleft = create_node(count_head->ch);
	Pright = create_node(count_head->next->ch);
	Pleft->count =  count_head->count;
	Pright->count = count_head->next->count;
	Ptr = count_head->next->next;
	
	while(1)
	{
		sum = create_node('\0');
		sum->count = Pleft->count + Pright->count;
		sum->left = Pleft;
		sum->next = Pright;
		if(Ptr == NULL)
		{	break;	}
		else if(sum->count > Ptr->count)
		{	Pright = sum;
			Pleft = create_node(Ptr->ch);
			Pleft->count = Ptr->count;

		}
		else
		{	Pleft = sum;
			Pright = create_node(Ptr->ch);
			Pright->count = Ptr->count;
		}
		Ptr = Ptr->next;
	}
	
return sum;	
}

int height(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->next);
 

        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}
 
void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout<<"    "<< root->ch << " "<<root->count;
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->next, level-1);
    }
}
void PrintTree()
{
	int h = height(TreeHead);
    int i;
    for (i = 1; i <= h; i++)
        {	printGivenLevel(TreeHead, i);
			cout<<"\n\n";	
		}
}

int CODE_FINDER(Node* ptr,long int num)
{
	if(ptr->next == NULL)
	{	cout<<ptr->ch<<"  "<<num<<"\n";		}
	else 
	{
		CODE_FINDER(ptr->left,num*10);
		CODE_FINDER(ptr->next,num*10+1);
	}
}

int main()
{
	string str = "aaannqqbbbbgebeheffdfhffghgeghggcggfggdghghhhhfhhdhchahhehhhfbhg" ;
	cout<<"\n\ngiven string is :  "<<str<<"\n\n";
	count_frequency(str);
	
	TreeHead = MakeTree();
	cout<<"\n***********************  HUFFMAN CODES FOR THE ALPHABETS ARE    ***********************\n";
	
	CODE_FINDER(TreeHead,0);

	return 0;
}

void SortCountList()
{	Node *ptr1=count_head,*ptr2;
	while(ptr1->next != NULL)
	{	ptr2=ptr1->next;
		while(ptr2 != NULL)
		{	if(ptr1->count > ptr2->count)
			{	swap(ptr1->count,ptr2->count);
				swap(ptr1->ch,ptr2->ch);
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}


