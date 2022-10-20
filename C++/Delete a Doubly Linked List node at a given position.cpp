
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del)
{

	if (*head_ref == NULL || del == NULL)
		return;

	if (*head_ref == del)
		*head_ref = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
}

void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{

	if (*head_ref == NULL || n <= 0)
		return;

	struct Node* current = *head_ref;
	int i;

	for (int i = 1; current != NULL && i < n; i++)
		current = current->next;

	if (current == NULL)
		return;

	deleteNode(head_ref, current);
}

void push(struct Node** head_ref, int new_data)
{

	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{

	struct Node* head = NULL;

	push(&head, 5);
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	cout << "Doubly linked list before deletion:n";
	printList(head);

	int n = 2;

	deleteNodeAtGivenPos(&head, n);

	cout << "\nDoubly linked list after deletion:n";
	printList(head);

	return 0;
}
