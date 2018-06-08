#include<stdio.h>
#include<stdlib.h>

//Define Linked List on Integer Node
struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void Menu() {
	int choose;
	int a,x,z;
	printf("\n------- Double Linked List Menu -------\n");
	printf ("Choose one action you will run (1-9): \n1. Insert Data at Head \n2. Insert Data at Tail \n3. Insert Data in the Middle \n4. Delete Data at Head \n5. Delete Data at Tail \n6. Delete Data in the Middle \n7. Print Forward \n8. Print Backward \n9. Exit\nAnswer: ");
	scanf ("%d", &choose);
	if (choose==1) {
		printf("Insert data at head: ");
		scanf("%d", &x);
		InsertAtHead(x);
	}
	else if (choose==2){
		printf("Insert data at tail: ");
		scanf("%d", &x);
		InsertAtTail(x);
	}
	else if (choose==3){
		struct Node *before;
		struct Node *after;
		printf("Insert data before: ");
		scanf("%d", &a);
		printf("Insert data: ");
		scanf("%d", &x);
		struct Node* newNode = GetNewNode(x);
		newNode->next=NULL;
		newNode->prev=NULL;
		printf("Insert data after: ");
		scanf("%d", &z);
		struct Node* temp = head;
		if(head == NULL) {
			head = newNode;
			return;
		}
		else if (temp->next == NULL) {
			temp->next = newNode;
			newNode->prev = temp;
		}
		else {
			after = head;
			do {
				before = after;
				after = after->next;
			}
			while (after != a && after->next != z);
			before->next=newNode;
			newNode->next=after;
			newNode->prev=before;
			after->prev=newNode;
/*
			data->next=after;
			data->prev=before;
			before->next=data;
			after->prev=data;
			*/
		}
	}
	else if (choose==7){
		Print();
	}
	else if (choose==8){
		ReversePrint();
	}
	else if (choose==9){
		printf("------- EXIT -------\n");
		exit(0);
	}
	else {
		printf("Invalid Menu.\n");
		Menu();
	}
	Menu();
}

int main() {
	head = NULL; // empty list. set head as NULL.
	Menu();
}
