#include<stdio.h>
#include<stdlib.h>

//Define Linked List on Integer Node
struct Node 
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x)
{
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void savetofile()
{
	struct Node* temp = head;
	FILE* file = fopen("data.txt", "w");
	if (temp->next == NULL)
		fprintf(file, "%d", temp->data);
	else
	{
		while (temp->next != NULL)
		{
			fprintf(file, "%d\n", temp->data);
			temp = temp->next;
		}
		fprintf(file, "%d", temp->data);
	}
	fclose(file);
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) 
{
	struct Node* newNode = GetNewNode(x);
	if (head == NULL) 
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
	savetofile();
}
void InsertAtBetween(int a, int x, int z)
{
	struct Node* newNode = GetNewNode(x);
	newNode->next = NULL;
	newNode->prev = NULL;
	struct Node* aNode = GetNewNode(a);
	struct Node* zNode = GetNewNode(z);
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	struct Node* temphead = head;
	if (head == NULL) 
	{
		head = newNode;
		return;
	}
	else if (temp->next == NULL) 
	{
		temp->next = newNode;
		newNode->prev = temp;
		head = temphead;
	}
	else 
	{
		while(1) 
		{
			if (temp2->data == zNode->data && temp->data == aNode->data)
				break;
			else if (temp2->next == NULL)
			{
				printf("Node 1 and Node 2 not found.\n");
				return;
			}
				else 
			{
				temp = temp->next;
				temp2 = temp->next;
			}
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = temp2;
		temp2->prev = newNode;
		head = temphead;
		
	}
	savetofile();
}
//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) 
{
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	struct Node* temphead = head;
	if (head == NULL) 
	{
		head = newNode;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	head = temphead;
	savetofile();
}
//Delete a Node at head
void DeleteAtHead() 
{
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	if (head == NULL)
	{
		printf("Empty List\n");
		return;
	}
	while (temp->prev != NULL)
		temp = temp->prev;
	head = temp2;
	temp2->prev = NULL;
	free(temp);
	savetofile();
}
//Delete a Node at tail
void DeleteAtTail() 
{
	struct Node* temp = head;
	struct Node* temp2;
	struct Node* temphead = head;
	if (head == NULL) 
		printf("Empty List\n" );
	while (temp->next != NULL)
		temp = temp->next; // Go To last Node
	temp2 = temp->prev;
	temp2->next = NULL;
	temp->prev = NULL;
	free(temp);
	head = temphead;
	savetofile();
}

//Delete between a Node 
void DeleteAtBetween(int a,int z) 
{
	struct Node* aNode = GetNewNode(a);
	struct Node* zNode = GetNewNode(z);
	struct Node* temp = head;
	struct Node* temp2 = temp->next;
	struct Node* temp3 = temp2->next;
	struct Node* temphead = head;
	if (head == NULL) 
		DeleteAtHead();
	else if (temp->next == NULL) 
		DeleteAtTail();
	else 
	{
		while(1) 
		{
			if (temp3->data == zNode->data && temp->data == aNode->data) 
				break;
			else if (temp3->next == NULL)
			{
				printf("Node 1 and Node 2 not found.\n");
				return;
			}	
			else 
			{
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
		head = temphead;
	}
	savetofile();
}

//Prints all the elements in linked list in forward traversal order
void Print() 
{
	struct Node* temp = head;
	struct Node* temphead = head;
	printf("Double Linked List Data Value: ");
	if (temp == NULL)
		printf("Empty List\n" );
	while (temp != NULL) 
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	head = temphead;
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() 
{
	struct Node* temp = head;
	struct Node* temphead = head;
	if (temp == NULL)
		printf("Empty List\n" );
	// Going to last Node
	while (temp->next != NULL)
		temp = temp->next;
	while(temp != NULL) 
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	head = temphead;
	printf("\n");
}
void Search(int x)
{
	int count;
	struct Node* temp = head;
	struct Node* temphead = head;
	if (head == NULL) 
	{
		printf("Empty List");
		return;
	}
	printf("\nData found on the list number : ");
	while (temp != NULL)
	{
		count++;
		if (temp->data == x)
			printf(" %d ", count);
		temp = temp->next;

	} 
	head = temphead;
}

void Menu() 
{
	int choose;
	int a,x,z;
	printf("\n------- Double Linked List Menu -------\n");
	printf("Choose one action you will run (1-9): \n1. Insert Data at Head \n2. Insert Data at Tail \n3. Insert Data Between 2 Node \n4. Delete Data at Head \n5. Delete Data at Tail \n6. Delete Data in the Middle \n7. Print Backward \n8. Search \n9. Exit \nAnswer: ");
	scanf("%d", &choose);
	if (choose == 1) 
	{
		printf("Insert data at head \nData Value: ");
		scanf("%d", &x);
		InsertAtHead(x);
		Print();
	}
	else if (choose == 2)
	{
		printf("Insert data at tail \nData Value: ");
		scanf("%d", &x);
		InsertAtTail(x);
		Print();
	}
	else if (choose == 3)
	{
		printf("Insert data between (node1,node2) \nExample: (2,5) \nType node1 and node2: ");
		scanf("%d,%d", &a, &z);
		printf("Data Value: ");
		scanf("%d", &x);
		InsertAtBetween(a,x,z);
		Print();
	}
	else if (choose == 4) 
	{
		printf("Delete data at head\n");
		DeleteAtHead(x);
		Print();
	}
	else if (choose == 5)
	{
		printf("Delete data at tail\n");
		DeleteAtTail(x);
		Print();
	}
	else if (choose == 6)
	{
		printf("Delete data between (node1,node2) \nExample: (2,5) \nType node1 and node2: ");
		scanf("%d,%d", &a, &z);
		DeleteAtBetween(a,z);
		Print();
	}
	else if (choose == 7)
	{
		printf("Print Backward: \n");
		ReversePrint();
	}
	else if (choose == 8)
	{
		printf("\nValue Data: ");
		scanf("%d", &x);
		Search(x);
	}
	else if (choose == 9)
	{
		printf("------- EXIT -------\n");
		exit(0);
	}
	else 
	{
		printf("Invalid Menu.\n");
		Menu();
	}
	Menu();
}

int main() 
{
	head = NULL; // empty list. set head as NULL.
	FILE* file = fopen("data.txt", "r");
	char line[256];
	int x;
	while (fgets(line, sizeof(line), file))
	{
		x = atoi(line);
		struct Node* newNode = GetNewNode(x);
		struct Node* temp = head;
		struct Node* temphead = head;
		if (head == NULL) 
		{
			head = newNode;
		}
		else 
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
			head = temphead;
		}
    	}
    	fclose(file);
	Menu();
}