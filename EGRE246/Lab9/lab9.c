#include <stdio.h>
#include <stdlib.h>

//Node definition
struct node{
	int data;
	struct node *next;
};

//Defining the linkedlist type
typedef struct node *llist;

//Function prototypes
llist createList();
void printList(llist);
llist addAtEnd(llist, int);
llist removeAtFront(llist);
void addAtFront(llist*, int);

int main(void){
	llist list = createList();
	printList(list); printf("\n");
	list = addAtEnd(list, 1); //printList(list); printf("\n");
	list = addAtEnd(list, 2);
	list = addAtEnd(list, 3);
	list = addAtEnd(list, 4);
	list = addAtEnd(list, 5);
	list = addAtEnd(list, 6);
	printList(list); printf("\n");
	list = removeAtFront(list);
	printList(list); printf("\n");
	addAtFront(&list, 7);
	printList(list); printf("\n");

	llist list2 = createList();
	addAtFront(&list2, 7);
	printList(list2); printf("\n");
	return 0;
}

llist createList(){
	return NULL;
}

void printList(llist list){
	if(list == NULL){
		printf("NULL");
	}else{
		llist ptr = list;
		while(ptr != NULL){
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
	}
}

llist addAtEnd(llist list, int n){
	llist newNode = malloc(sizeof(struct node));
	newNode->data = n; newNode->next = NULL;
	if(list == NULL){
		return newNode;
	}else{
		llist ptr = list;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode;
		return list;
	}
}

llist removeAtFront(llist list){
	if(list != NULL){
		llist ptr = list;
		list = ptr->next;
		free(ptr);
	}
	return list;
}

void addAtFront(llist* list, int n){
	llist newNode = malloc(sizeof(struct node));
	newNode->data = n; newNode->next = NULL;
	newNode->next = *list;
	*list = newNode;
}
