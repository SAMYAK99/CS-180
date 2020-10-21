/*Design and develop a program for an institution having three departments Computer Engineering,
Electronics and mechanical. The institute considers SSC, HSC and entry test marks for registering a
student and calculate an aggregate based on a specific criteria. The program should find in which
dept. a student should be registered, store its record and provide facility for adding other
departments in the institute and changing admission criteria and provide a facility for retrieving a
record of particular student.*/

#include<iostream>
using namespace std;

class node
{
public:
 float hsc, ssc, cet;
 int id;
 node *next;
 void getinfo()
 {
 cout<<"Enter the ID of student :-";
cin>>id;
 cout<<"Enter the SSC marks of student :-";
cin>>ssc;
 cout<<"Enter the HSC marks of student :-";
 cin>>hsc;
 cout<<"Enter the CET marks of student :-";
 cin>>cet;
 }
 float avg()
 {
 return ((ssc+hsc+cet)/3);
 }
};

class sll
{
 public:
 node *head;
 sll()
 {
 head = NULL;
 }
 void insert(node s);
 void display();
 int search(int id);
};

void sll::insert(node s){
 node *temp, *p;
 p=head;
 temp = new node;
 temp->id = s.id;
 temp->ssc = s.ssc;
 temp->hsc = s.hsc;
 temp->cet = s.cet;
 temp->next = NULL;
 if(head==NULL)
 {
 head = temp;
 }
else
{
 while(p->next != NULL)
 {
 p=p->next;
 }
 p->next = temp;
}
}

void sll::display(){
 node *p;
 p=head;
 if(head==NULL)
 {
 cout<<"Student not Register..";
 }
 while(p!= NULL)
 {
 cout<<"\nID:"<< p->id<<endl;
 cout<<"SSC Marks:"<<p->ssc<<endl;
 cout<<"HSC Marks:"<<p->hsc<<endl;
 cout<<"CET Marks:"<<p->cet<<endl<<endl;
 p=p->next;
 }
}

int sll::search(int id)
{
 node *p;
 int flag=0;
 p=head;
 while(p!=NULL)
 {
 if (p->id==id)
 {
 flag = 1;
break;
 }
 else
 p=p->next;
 }
 return flag;
 cout<<"Student does not exist";
}

int main()
{
node a;
int choice, ch;
sll comp, mech, entc;
do
{
 cout<<"1. Registration"<<endl;
 cout<<"2. Search"<<endl;
 cout<<"3. Display"<<endl;
 cout<<"4. Exit"<<endl;
 cout<<"Enter your choice "<<endl;
 cin>>choice;
 switch(choice)
 {
 case 1:
 a.getinfo();
float marks;
marks=a.avg();
if (marks>=85)
 comp.insert(a);
 else if (marks<85 && marks>=70)
 mech.insert(a);
 else
 entc.insert(a);
 break;
 case 2:
 int id;
cout<<"Enter ID:"<<endl;
cin>>id;
if(comp.search(id))
 cout<<"Student is in computer department"<<endl<<endl;
 if(mech.search(id))
 cout<<"Student is in mechanical department"<<endl<<endl;
 if(entc.search(id))
 cout<<"Student is in entc department"<<endl<<endl;
 break;
 case 3:
 cout<<"\nComputer Department->";
 comp.display();
cout<<"\nMechanical Department->";
 mech.display();
cout<<"\nEnTC Department->";
 entc.display();
break;
 default:
 cout<<"Wrong Choice..";
 }
 cout<< "\nDo you want to continue(1/0)";
 cin>>ch;
} while(ch==1);
 return 0;
}
