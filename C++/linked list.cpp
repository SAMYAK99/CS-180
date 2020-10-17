#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insert(struct Node **head, int newData);
void printList(struct Node* head);
void deleteNode(struct Node** head, int position);

int main()
{   
    Node* head = NULL;

    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 9);

    cout<<"Created"<< endl;
    printList(head);
    deleteNode(&head, 4);
    cout<<"\nAfter delettion of position 4 "<<endl;
    printList(head);
    return 0;


}

void insert(struct Node** head, int newData)
{
    struct Node  *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node** head, int position)
{
    // if the list is empty
    if(*head == NULL)
        return;

    // create new pointer to head
    struct Node* temp = *head;
    //if they want to delete head, move head
    // to next item, delete and return
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    // cycle through list until end or node postion
    for (int i=0; temp!=NULL && i<position-1; i++)
    {   
        temp = temp->next;
    }
    // if end if list, return
    if (temp == NULL || temp->next == NULL)
        return;
    //create new pointer to point ot positions pointer
    struct Node *next =  temp->next->next;
    // delete postion
    free(temp->next);
    //unlink node
    temp->next = next;
}

void printList(struct Node *head)
{
    while(head != NULL)
    {
        cout<< head->data <<endl;
        head = head->next;
    }
}