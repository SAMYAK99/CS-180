// C program to traverse the linked list

#include <stdio.h>

#include <stdlib.h>

//Self-referential structure to create node.
typedef struct tmp {
        int item;
        struct tmp * next;
}
Node;

//structure for create linked list.
typedef struct {
        Node * head;
        Node * tail;

}
List;

//Initialize List
void initList(List * lp) {
        lp -> head = NULL;
        lp -> tail = NULL;
}

//Create node and return reference of it.
Node * createNode(int item) {
        Node * nNode;

        nNode = (Node * ) malloc(sizeof(Node));

        nNode -> item = item;
        nNode -> next = NULL;

        return nNode;
}

//Add new item at the end of list.
void addAtTail(List * lp, int item) {
        Node * node;
        node = createNode(item);

        //if list is empty.
        if (lp -> head == NULL) {
                lp -> head = node;
                lp -> tail = node;
        } else {
                lp -> tail -> next = node;
                lp -> tail = lp -> tail -> next;
        }
}

//Add new item at begning of the list.
void addAtHead(List * lp, int item) {
        Node * node;
        node = createNode(item);

        //if list is empty.
        if (lp -> head == NULL) {
                lp -> head = node;
                lp -> tail = node;
        } else {
                node -> next = lp -> head;
                lp -> head = node;
        }
}

//To print list from start to end of the list.
void TraverseList(List * lp) {
        Node * node;

        if (lp -> head == NULL) {
                printf("\nEmpty List");
                return;
        }

        node = lp -> head;

        printf("List:\n");
        while (node != NULL) {
                printf("| %05d |", node -> item);
                node = node -> next;

                if (node != NULL)
                        printf("--->");
        }
        printf("\n\n");
}

//Main function to execute program.
int main() {
        List * lp;

        lp = (List * ) malloc(sizeof(List));

        initList(lp);

        addAtTail(lp, 100);
        addAtTail(lp, 200);
        addAtHead(lp, 300);
        addAtHead(lp, 400);
        addAtHead(lp, 500);

        TraverseList(lp);

        return 0;
}
