#include<iostream>
using namespace std;

class node{
    public:
int  data;
 node *next;
}head;
node * reverse_LL_recursion(node * head)
{
if(head->next==NULL)
return head;
else{
node*temp=reverse_LL_recursion(head->next);
head->next->next=head;
head->next=NULL;
return temp;
}
}


void display_LL(node *head)
{
    node *ptr=head;
    while(ptr)
    {
        cout<<ptr->data<<" "<<endl;
        ptr=ptr->next;
    }
}

node *Insert_at_beg(node *head,node *newnode)
{
if (head==0)
{
    head=newnode;
}
else{
    newnode->next=head;
    head=newnode;
}
return head;
}

int main()
{
  int n;
    cout<< "Input the Number of Linklist You Want ?"<<endl;
cout<<"Enter Your Choice : ";
cin>>n;
   node *head=0;
while(n){
    
int data;
        cout <<"Enter The Data :";
        cin>>data;
       node *newnode=new node;
        newnode->data=data;
        newnode->next=NULL;
        head=Insert_at_beg(head,newnode);
     
        n--;
}
head=reverse_LL_recursion(head);
cout<<"The new Linked list is "<<endl;
display_LL(head);
return 0;
}
