#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* next;
	int data;
} Node_t;


void
list_reverse(Node_t** phead)
{
	Node_t* p = *phead, *q = *phead;
	if (p->next == NULL)
		return;
	q = p->next;
	while (q) {
		Node_t* temp = q->next;
		q->next = p;
		p = q;
		q = temp;
	}
	(*phead)->next->next = NULL;
	(*phead)->next = p;
}

void
list_init(Node_t** head)
{
	*head = (Node_t*)malloc(sizeof(Node_t));
	if (*head == NULL) {
		printf("malloc error\n");
		return;
	}
	(*head)->next = NULL;
}

void
list_add(Node_t* head, int data)
{
	Node_t* node = (Node_t*)malloc(sizeof(Node_t));
	if (node == NULL) {
		printf("malloc error\n");
		return;
	}
	node->data = data;
	node->next = head->next;
	head->next = node;
}

void
list_destroy(Node_t* head)
{
	Node_t* p = head, *q = head;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
}

void
list_print(Node_t* head)
{
	head = head->next;
	while (head != NULL) {
		printf("%d  ", head->data);
		head= head->next;
	}
	printf("\n");
}

int
main()
{
	Node_t* head;
	list_init(&head);
	int iter;
	for (iter = 0; iter < 10; iter++)
		list_add(head, iter);
	list_reverse(&head);
	list_print(head);
	list_destroy(head);
	return 0;
}
