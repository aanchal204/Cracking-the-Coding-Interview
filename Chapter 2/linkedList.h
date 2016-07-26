typedef struct node{
	int val;
	struct node* next;
}node;
void insertAtTail(node **head, int x);
void printLL(node *head);
node * createLL(void);
int lengthLL(node *head);