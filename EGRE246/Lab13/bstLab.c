#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
  // bst node definiton here
  struct node *left;
  struct node *right;
  int data;
};

struct bstType {
  struct node *root;
};

typedef struct bstType *bst;

bst createBST();
struct node *insertNode(struct node *,int);
void insertItem(bst,int);
void inOrder(struct node *,void (*f)());
void inorder(bst,void (*f)());

void print(int n) {
  printf("%d ",n);
}

int main(void) {
  bst t = createBST();
  time_t x; srand((unsigned)time(&x));
  for(int i = 1; i <= 20; i++)
    insertItem(t,rand()%100);
  inorder(t,print);
  printf("\n");
}

bst createBST(){
	bst t = malloc(sizeof(struct bstType));
	t->root = NULL;
	return t;
}

struct node *insertNode(struct node *t, int item){
	if(t==NULL){
		t = malloc(sizeof(struct node));
		t->data = item; t->left = t->right = NULL;
	}else if(t->data > item){
		t->left = insertNode(t->left, item);
	}else if(t->data < item){
		t->right = insertNode(t->right, item);
	}else{
		printf("Duplicate item %d ignored", item);
	}
	return t;
}

void insertItem(bst t, int item){
	t->root = insertNode(t->root, item);
}

void inOrder(struct node *t, void (*f)()){
	if(t != NULL){
		inOrder(t->left, f); f(t->data); inOrder(t->right, f);
	}
}

void inorder(bst t, void (*f)()){ inOrder(t->root, f); }
