#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 100

struct stackType{
	int data[MAX_SIZE];
	int top;
	bool isEmpty;
	bool isFull;
};

stack createStack(){
	stack s = malloc(sizeof(struct stackType));
	s->top = -1;
	return s;
}

void push(stack s, int n){
	if(isFull(s)){
		printf("error(push): stack overflow");
		exit(EXIT_FAILURE);
	}else{
		s->data[++s->top] = n;
	}
}
void pop(stack s){
	if(isEmpty(s)){
		printf("error(pop): stack underflow");
		exit(EXIT_FAILURE);
	}else{
		s->top--;
	}
}

int top(stack s){
	if(isEmpty(s)){
		printf("error(top): stack underflow");
		exit(EXIT_FAILURE);
	}else{
		return s->data[s->top];
	}
}

bool isEmpty(stack s){
	return s->top == -1;
}

bool isFull(stack s){
	return s->top == MAX_SIZE-1;
}

int size(stack s){
	return s->top+1;
}

int getItem(stack s, int i){
	return s->data[i];
}

void setItem(stack s, int i, int n){
	s->data[i] = n;
}
