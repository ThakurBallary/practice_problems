/*
Given an sll and number. insert number in its appropriate position
example: 1->10 and 5
1->5->10

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* createNewnode(int data) {
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void insert_ascending(struct node **head, int data) {
	if (!*head) {
		*head = createNewnode(data);
		return;
	}
	struct node *temp = *head;
	if (data < temp->data) {
		*head = createNewnode(data);
		(*head)->next = temp;
		return;
	}
	struct node *prev = temp;
	temp = temp->next;
	while (temp) {	
		if (data < temp->data) {
			prev->next = createNewnode(data);
			prev->next->next = temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (!temp) {
		prev->next = createNewnode(data);
	}	
}