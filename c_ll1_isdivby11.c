/*
Find whether the given sll is divisible by 11 or not
example:
input: 1->2->1
output: return 1 if divisible by 11 else return 0

*/

#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

int get_alternate_sum(struct node *head) {
	int sum = 0;
	while (head) {
		sum += head->data;
		if (head->next) {
			head = head->next->next;
		}
		else {
			head = head->next;
		}
	}
	return sum;
}

int isdivby11(struct node *head) {
	if (!head) {
		return 0;
	}
	int oddSum = get_alternate_sum(head);
	int evenSum = get_alternate_sum(head->next);
	if (oddSum == evenSum) {
		return 1;
	}
	return 0;
}
