//various operations on double linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head, *tail;

void create(){
    struct Node *new, *ptr;
    int i=0;
    char ch;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    new->next = NULL;
    new->prev = NULL;
    head = new;
    ptr = head;
    fflush(stdin);

    while(i!=1){
        printf("Do you want to add(Y/N): ");
        scanf("%c", &ch);
        if(ch == 'Y' || ch == 'y'){
            new = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter value: ");
            scanf("%d", &new->data);
            new->next = NULL;
            ptr->next = new;
            new->prev = ptr;
            ptr = new;
            fflush(stdin);
        }
        else{
            i=1;
        }
    }
}

void traverse(){
    struct Node *ptr;
    ptr = head;
    printf("The list is:");
    while(ptr!=NULL){
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}

void insert_first(){
    struct Node *new, *ptr;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    ptr = head;
    new->next = head;
    head->prev = new;
    head = new;
    new->prev = NULL;
}

void insert_last(){
    struct Node *new, *ptr, *tail;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    tail = ptr;
    ptr->next = new;
    new->prev = ptr;
    new->next = NULL;
    tail = new;
}

void insert_pos(){
    struct Node *ptr, *new;
    int pos, count=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    ptr = head;
    while(ptr!=NULL && count !=pos-1){
        ptr = ptr-> next;
        count++;
    }
    new->next = ptr->next;
    new->prev = ptr;
    (ptr->next)->prev = new;
    ptr->next = new;
}

void delete_first(){
    struct Node *ptr;
    ptr = head;
    (ptr->next)->prev = NULL;
    head = ptr->next;
}

void delete_last(){
    struct Node *ptr, *temp;
    ptr = head;
    while((ptr->next) != NULL){
        ptr = ptr->next;
    }
    temp = ptr;
    ptr = ptr->prev;
    ptr->next = NULL;
    free(temp);
}

void delete_pos(){
    struct Node *ptr, *temp;
    ptr = head;
    int count = 1, pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    while(ptr!=NULL && count != pos-1){
        ptr = ptr->next;
        count++;
    }
    temp = ptr->next;
    (temp->next)->prev = ptr;
    ptr->next = temp->next;
    free(temp);
}

void reverse(){
    printf("List in reverse:");
    struct Node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    while(ptr != NULL){
        printf(" %d", ptr->data);
        ptr = ptr->prev;
    }
}

int main(){
    int num;
    int t=0;
    while(t!=1){
        printf("\n\n1. Create a Linked list\n2. Display the linked list\n3. Insert an element at first\n4. Insert an element at last\n5. Insert an element at given position");
        printf("\n6. Delete element at first\n7. Delete element at last\n8. Delete element at given position\n9. Display in reverse\n10. Exit\n\nEnter your choice: ");
        scanf("%d", &num);
        fflush(stdin);

        switch(num){
            case 1:
                create();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insert_first();
                traverse();
                break;
            case 4:
                insert_last();
                traverse();
                break;
            case 5:
                insert_pos();
                traverse();
                break;
            case 6:
                delete_first();
                traverse();
                break;
            case 7:
                delete_last();
                traverse();
                break;
            case 8:
                delete_pos();
                traverse();
                break;
            case 9:
                reverse();
                break;
            case 10:
                t=1;
                printf("Exited");
                break;
            default:
                printf("Invalid input");
        }
    }

    return 0;
}