#include<iostream>
#include<stdio.h>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue(){front=rear=-1;size=10;Q=new Node*[size];}
    Queue(int size){front=rear=-1;this->size=10;Q=new Node*[this->size];}
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty(){return front==rear;}
    void Display();
};

void Queue::enqueue(Node *x)
{
    if(rear == size-1)
        printf("Queue is Fill\n");
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node* x=NULL;
    if(front == rear)
        printf("Queue is Empty\n");
    else
    {
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    {
        printf("%d ",Q[i]);
    }
    printf("\n");
}

class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    void Height(Node *root);
};


void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Enter root value");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);

        }
         printf("Enter right child");
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);

        }
    }
}


void Tree::Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}


int main()
{
    Tree t;
    t.CreateTree();
    cout<<"Preorder ";
    t.Preorder(t.root);
    cout<<endl;
    cout<<"Inorder ";
    t.Inorder(t.root);
    cout<<endl<<endl;

    return 0;
}
