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
void InsertAtBetween(int a, int x, int z){
	struct Node* newNode = GetNewNode(x);
	newNode->next=NULL;
	newNode->prev=NULL;
	struct Node* aNode = GetNewNode(a);
	struct Node* zNode = GetNewNode(z);
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	if(head == NULL) {
		head = newNode;
		return;
	}
	else if (temp->next == NULL) {
		temp->next = newNode;
		newNode->prev = temp;
	}
	else {
		while(1) {
			if (temp2->data == zNode->data && temp->data == aNode->data) break;
			else {
				temp = temp->next;
				temp2 = temp->next;
			}
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = temp2;
		temp2->prev = newNode;
	}

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
//Delete a Node at head
void DeleteAtHead() {
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	if(head == NULL) {
		return;
	}
	while(temp->prev != NULL) temp = temp->prev;
	head=temp2;
	temp2->prev=NULL;
	free(temp);
}
//Delete a Node at tail
void DeleteAtTail() {
	struct Node* temp = head;
	struct Node* temp2;
	if(head == NULL) {
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp2=temp->prev;
	temp2->next=NULL;
	temp->prev=NULL;
	free(temp);
}

//Delete between a Node 
void DeleteAtBetween(int a,int z) {
	struct Node* aNode = GetNewNode(a);
	struct Node* zNode = GetNewNode(z);
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	struct Node* temp3 = temp2->next;
	if(head == NULL) {
		DeleteAtHead();
	}
	else if (temp->next == NULL) {
		DeleteAtTail();
	}
	else {
		while(1) {
			if (temp3->data == zNode->data && temp->data == aNode->data) break;
			else {
				temp = temp->next;
				temp2 = temp->next;
				temp3 = temp2->next;
			}
		}
		temp3->prev = temp;
		temp->next = temp2->next;
		temp2->next = NULL;
		temp2->prev = NULL;
		free(temp2);
	}
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Double Linked List Data Value: ");
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
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
void Search(int x){
	int count;
	struct Node* temp = head;
	if(head == NULL) {
		printf("Empty List");
		return;
	}
	printf("\nData found on the list number : ");
	while(temp != NULL){
		count++;
		if (temp->data==x){
			printf(" %d ", count);
		}
		temp = temp->next;

	} 
}

void Menu() {
	int choose;
	int a,x,z;
	printf("\n------- Double Linked List Menu -------\n");
	printf ("Choose one action you will run (1-9): \n1. Insert Data at Head \n2. Insert Data at Tail \n3. Insert Data Between 2 Node \n4. Delete Data at Head \n5. Delete Data at Tail \n6. Delete Data in the Middle \n7. Print Backward \n8. Search \n9. Exit \nAnswer: ");
	scanf ("%d", &choose);
	if (choose==1) {
		printf("Insert data at head \nData Value: ");
		scanf("%d", &x);
		InsertAtHead(x);
		Print();
	}
	else if (choose==2){
		printf("Insert data at tail \nData Value: ");
		scanf("%d", &x);
		InsertAtTail(x);
		Print();
	}
	else if (choose==3){
		printf("Insert data between (node1,node2) \nExample: (2,5) \nType node1 and node2: ");
		scanf("%d,%d", &a, &z);
		printf("Data Value: ");
		scanf("%d", &x);
		InsertAtBetween(a,x,z);
		Print();
	}
	if (choose==4) {
		printf("Delete data at head \nData Value: ");
		DeleteAtHead(x);
		Print();
	}
	else if (choose==5){
		printf("Delete data at tail \nData Value: ");
		DeleteAtTail(x);
		Print();
	}
	else if (choose==6){
		printf("Delete data between (node1,node2) \nExample: (2,5) \nType node1 and node2: ");
		scanf("%d,%d", &a, &z);
		DeleteAtBetween(a,z);
		Print();
	}
	else if (choose==7){
		printf("Print Backward: \n");
		ReversePrint();
	}
	else if (choose==8){
		printf("\nValue Data: ");
		scanf("%d", &x);
		Search(x);
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