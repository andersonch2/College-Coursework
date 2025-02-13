#include <stdio.h>
#include <stdlib.h>

//Node definition
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

//Defining the linkedlist type
typedef struct node *llist;

//Function prototypes
llist createList();
void printList(llist);
llist addAtEnd(llist, int);
llist removeAtFront(llist);
void addAtFront(llist*, int);
void revPrintList(llist);
llist endOfList(llist);

int main(void){
	llist list = createList();
	printList(list); printf("\n");

	list = addAtEnd(list, 1); //printList(list); printf("\n");
	list = addAtEnd(list, 2);
	list = addAtEnd(list, 3);
	list = addAtEnd(list, 4);
	list = addAtEnd(list, 5);
	list = addAtEnd(list, 6);

	printList(list);
	printf("\n");

	list = removeAtFront(list);
	printList(list); printf("\n");
	addAtFront(&list, 7);
	printList(list); printf("\n");
	revPrintList(list); printf("\n");

	llist list2 = createList();
	addAtFront(&list2, 7);
	printList(list2); printf("\n");

	llist list3 = list;
	for(int i=0; i<2; i++){
		list3 = list->next;
	}
	revPrintList(list3);

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
	newNode->data = n; newNode->next = NULL; newNode->prev = NULL;
	if(list == NULL){
		return newNode;
	}else{
		llist ptr = list;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode; newNode->prev = ptr;
		return list;
	}
}

llist removeAtFront(llist list){
	if(list != NULL){
		llist ptr = list;
		list = ptr->next; list->prev = NULL;
		free(ptr);
	}
	return list;
}

void addAtFront(llist* list, int n){
	llist newNode = malloc(sizeof(struct node));
	if(*list == NULL){
		newNode->data = n; newNode->next = NULL; newNode->prev = NULL;
		*list = newNode;
	}
	else{
		newNode->data = n; newNode->next = NULL; newNode->prev = NULL;
		newNode->next = *list; (*list)->prev = newNode;
		*list = newNode;
	}
}
llist endOfList(llist list){
	llist ptr = list;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	return ptr;
}

void revPrintList(llist list){
	if(list == NULL) printf("NULL");
	else{
		llist ptr = list;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		printf("%d ", ptr->data);
		while(ptr->prev != NULL){
			ptr = ptr->prev;
			printf("%d ", ptr->data);
		}
	}
}

//Below is the lab implementation of revPrintList
// void revPrintList(llist list){
// 	if(list == NULL) printf("NULL");
// 	else{
// 		llist ptr = list;
// 		printf("%d ", ptr->data);
// 		while(ptr->prev != NULL){
// 			ptr = ptr->prev;
// 			printf("%d ", ptr->data);
// 		}
// 	}
// }
