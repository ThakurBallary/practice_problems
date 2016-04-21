/*
Delete every other node of a given sll
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void delete_alternate_node(struct node **head) {
	if (!*head) {
		return;
	}
	struct node *temp = *head;
	*head = temp->next;
	struct node *prev = *head;
	int flag = 1;
	while (temp && prev) {
		free(temp);
		if (prev->next) {
			temp = prev->next;
			prev->next = temp->next;
			prev = prev->next;
		}
		else {
			temp = NULL;
		}
	}
}
