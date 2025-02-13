#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void){
	stack s = createStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	for(int i=0; i<size(s); i++){
		printf("%d ", getItem(s, i));
	}
	printf("\n");
	pop(s);
	setItem(s, 1, 7);
	for(int i=0; i<size(s); i++){
		printf("%d ", getItem(s, i));
	}
	printf("\n");
	return 0;
}
