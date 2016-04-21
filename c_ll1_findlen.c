/*
Find the length of the sll
*/

#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

int length(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}