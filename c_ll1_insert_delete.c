/*
Write functions for insert and delete node at specific index
*/

struct node {
	int data;
	struct node *next;
};

struct node * createNode(int data) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void insert_node_at_n(struct node **head, int data, int index){
    struct node *temp = *head;
    struct node *newnode = createNode(data);
    if(index == 1){ // insert_node_at_first
        if(*head == NULL){
            newnode->next = NULL;
            *head = newnode;
        } else {
            newnode->next = temp;
            *head = newnode;
        }
    } else {
        struct node *prev;
        // if index is greater than the no.of nodes, node will be inserted at the last
        while(index > 1 && temp != NULL){
            prev = temp;
            temp = temp->next;
            index--;
        }
        newnode->next = temp;
        prev->next = newnode;
    }
}

int length(struct node *head){
    struct node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_nth_node(struct node **head, int n){
    int len = length(*head);
    if(n > len){
        // printf("Node at %d does not exist. Only %d node(s) present.\n",n,len);
        return;
    }
    if(*head != NULL){
        struct node *temp = *head;
        if(n == 1){
            *head = temp->next;
            free(temp);
        } else {
            struct node *prev = NULL;
            while(n > 1){
                prev = temp;
                temp = temp->next;
                n--;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}
