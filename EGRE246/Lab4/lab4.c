#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy
#include <ctype.h>   // for isspace

#define TEXT_LENGTH 250
// #define MAX_DB_SIZE 1000
#define MAX_DESCRIPTION_SIZE 160
int listSize = 0, arraySize = 0;

typedef struct wType {
  int id; // widget id number
  int num; // number in stock
  float cost; // our unit cost
  char *des;  // description of item
} widget;

// void initDB(widget *[],int); // initialize database (db) to all NULL
int count(widget *); // returns count of actual items in db
widget *newItem(int, int, float, char *); // creates and returns a new db item
void printItem(widget); // prints a single db item
void printDB(widget*,int); // prints all db items
widget *insert(widget*, widget*);

///////////////////////////////////////

int main(void){
  widget* db = NULL;
  int total;

  //initDB(db,MAX_DB_SIZE);
  printf("# items in database: %d\n",count(db));
  printf("enter how many items? ");
  scanf("%d",&total);
  if(total <= 0) exit(EXIT_SUCCESS);

  int id,num; float cost; char des[MAX_DESCRIPTION_SIZE], ch;
  des[0] = '\0';
  for(int i = 0; i < total; i++) {
	printf("listSize: %d \narraySize: %d\n", listSize, arraySize);
    printf("Item #%d\n",i+1);
    printf("  stock number: "); scanf("%d",&id);
    printf("  # in stock: ");   scanf("%d",&num);
    printf("  unit cost: ");    scanf("%f",&cost);
    printf("  description: ");
    while(isspace(ch=getchar())) ; // see notes in handout on this
    ungetc(ch,stdin);
    scanf("%[^\n]",des);
	db = insert(db, newItem(id,num,cost,des));
    // db[i] = newItem(id,num,cost,des);
  }
  printf("listSize: %d \narraySize: %d\n", listSize, arraySize);
  printf("\nDatabase contents:\n");
  printDB(db,total);
  return 0;
}

//Insert essentially allows for our array to grow
//We create a new array, allocate extra memory to it, copy over the original list
//Then free the wasted memory
widget *insert(widget* db, widget* item){
	widget *l = db;
	if(listSize >= arraySize){
		l = (widget*)malloc((arraySize = arraySize + 2)*sizeof(widget));
		if(db != NULL){
			for(int i=0; i<listSize; i++){
				l[i] = db[i];
			}
			free(db);
		}
	}
	l[listSize++] = *item;
	free(item);
	return l;
}

widget *newItem(int id, int num, float cost, char* des){
	widget* temp = malloc(sizeof(widget));
	temp->id = id;
	temp->num = num;
	temp->cost = cost;
	temp->des = malloc(strlen(des)+1);
	strcpy(temp->des, des);
	return temp;
}

void printItem(widget item){
	printf("  Stock number: %d\n", item.id);
	printf("  Number in stock: %d\n", item.num);
	printf("  Unit cost: %f\n", item.cost);
	printf("  Description: %s\n", item.des);
	printf("\n");
}

// void initDB(widget* list[], int n){
// 	if(n<1) return;
// 	for(int i=0; i<n; i++){
// 		list[i] = NULL;
// 	}
// }

int count(widget* list){
	return listSize;
}

void printDB(widget* db, int size){
	int c = listSize;
	if(c<= 0){
		printf("Database is empty\n");
		return;
	}
	for(int i=0; i<size; i++){
		printf("Item Number #%d\n", i+1);
		printItem(db[i]);
	}
}
