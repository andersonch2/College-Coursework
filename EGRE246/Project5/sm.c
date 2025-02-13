//Cade Anderson Project 5
//EGRE246 11/28/2022
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "SMinstr.h"
#include "stack.h"


//TODO: DONE

void clear(stack);
void halt();
void neg(stack);
void dup(stack);
void add(stack);
void sub(stack);
void mul(stack);
void divide(stack);
void ldc(stack, int);
void out(stack);
void debug(stack);
void swap(stack);

int main(int argc, char *argv[]){
	//Input and Initialization
	int pc = 0; //Program counter to 0
	int code = -1; //OPCODE
	char *nextIns = malloc(sizeof(char)*100); //String for the instructions
	int nextInt = 0; //Creating an integer to use for LDC and INP
	FILE *fp; //File pointer
	char fileName[30]; //Name of the file
	stack sm = createStack(); //This is the stack machine
	int TRACE = 0; //Trace OFF to start
	int scan = 0;
	//Here i check to make sure a file was passed in, then create a file pointer
	if(argc > 1){
		strcpy(fileName, argv[1]);
	}else{
		exit(EXIT_FAILURE);
	}
	fp = fopen(fileName, "r");

	while(1){
		scan = fscanf(fp, "%s", nextIns);
		if(scan == EOF){
			printf("[warning - no HALT instruction]");
			halt();
		}
		code = toOpcodeNum(nextIns);
		//This loop turn the instructions to all upper case
		for(int i=0; i<strlen(nextIns); i++){
			nextIns[i] = toupper(nextIns[i]);
		}
		//printf("%s %d\n", nextIns, code);
		switch(code){
			case NOTHING: //This is for comments and illegal commands
					if(nextIns[0] == '%'){// Checks that it is a comment and then continues to a newline
						if(strstr(nextIns, "\n")){
								continue;
						}else{ //What i probably should have done here is get one character until i get a newline
							fgets(nextIns, 100, fp);
						}
					}else{
						printf("[error - illegal command '%s']", nextIns);
						halt();
					}
				break;
			case 0: //CLR
				if(TRACE){ printf("[trace - pc #%d: CLR]\n", pc); }
				clear(sm);
				pc++;
				break;
			case 1:  //HALT
				if(TRACE){ printf("[machine halted]"); }
				halt();
				pc++;
				break;
			case 2: //NEG
				if(TRACE){ printf("[trace - pc #%d: NEG]\n", pc); }
			 	neg(sm);
				pc++;
				break;
			case 3: //DUP
				if(TRACE){ printf("[trace - pc #%d: DUP]\n", pc); }
				dup(sm);
				pc++;
				break;
			case 4: //ADD
				if(TRACE){ printf("[trace - pc #%d: ADD]\n", pc); }
				add(sm);
				pc++;
				break;
			case 5: //SUB
				if(TRACE){ printf("[trace - pc #%d: SUB]\n", pc); }
				sub(sm);
				pc++;
				break;
			case 6: //MUL
				if(TRACE){ printf("[trace - pc #%d: MUL]\n", pc); }
				mul(sm);
				pc++;
				break;
			case 7: //DIV
				if(TRACE){ printf("[trace - pc #%d: DIV]\n", pc); }
				divide(sm);
				pc++;
				break;
			case 8: //LDC
				scan = fscanf(fp, "%d", &nextInt);
				if(scan == 0){ printf("[warning - illegal input ignored]\n"); continue; }
				if(TRACE){ printf("[trace - pc #%d: LDC %d]\n", pc, nextInt); }
				ldc(sm, nextInt);
				pc++;
				break;
			case 9: //INP
				printf("input: ");
				scanf("%d", &nextInt);
				if(TRACE){ printf("[trace - pc #%d: INP %d]\n", pc, nextInt); }
				ldc(sm, nextInt);
				pc++;
				break;
			case 10: //OUT
				if(TRACE){ printf("[trace - pc #%d: OUT]\n", pc); }
				out(sm);
				pc++;
				break;
			case 11: //DBG
				if(TRACE){ printf("[trace - pc #%d: DBG]\n", pc); }
				debug(sm);
				pc++;
				break;
			case 12: //TRACE
				if(TRACE){ printf("[trace - pc #%d: TRA]\n", pc); }
				TRACE = (TRACE==0)?1:0;
				pc++;
				break;
			case 13: //SWAP
				if(TRACE){ printf("[trace - pc #%d: SWAP]\n", pc); }
				swap(sm);
				pc++;
				break;
		}
	}
	return 0;
}

//Below are the functions for each of the stack machine commands
//CLR: Clears the stack to empty
void clear(stack s){
	while(!isEmpty(s)){
		pop(s);
	}
}
//HALT: Halts the stack machine (exits program)
void halt(){
	exit(EXIT_SUCCESS);
}

//NEG: negates the top of the stack
void neg(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n = top(s);
	n = (-1)*n;
	pop(s);
	push(s, n);
}

//DUP: Duplicates the item on the top of the stack
void dup(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n = top(s);
	push(s, n);
}

//SWAP: swaps the top two items on the stack
void swap(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n1 = top(s); pop(s);
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n2 = top(s); pop(s);
	push(s, n1); push(s, n2);
}
//ADD: Adds the top two items on the stack and pushes the result onto the stack
void add(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n1 = top(s); pop(s);
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n2 = top(s); pop(s);
	int sum = n1 + n2; push(s, sum);
}

//SUB: Subtracts top two items, pushes the result
void sub(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n1 = top(s); pop(s);
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n2 = top(s); pop(s);
	int diff = n1 - n2; push(s, diff);
}

//MUL: Multiplies top two items, pushes the result
void mul(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n1 = top(s); pop(s);
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n2 = top(s); pop(s);
	int prod = n1*n2; push(s, prod);
}

//DIV: Divides top two items, pushes the result
void divide(stack s){
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n1 = top(s); pop(s);
	if(isEmpty(s)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n2 = top(s); pop(s);
	if(n2 == 0){
		printf("[error - division by zero]");
		exit(EXIT_FAILURE);
	}else{
		int diff = n1/n2; push(s, diff);
	}
}

//LCD n: Loads integer n to top of stack
void ldc(stack s, int n){
	push(s, n);
}
//INP: Reads keyboard input, pushes to top of stack
//INPUT REUSES THE LDC FUNCTION, ONLY GETS THE DATA DIFFERENTLY

//OUT: Pops the top of the stack, prints the value plus a newline
void out(stack sm){
	if(isEmpty(sm)){
		printf("[error - empty stack]\n");
		exit(EXIT_FAILURE);
	}
	int n = top(sm);
	pop(sm);
	printf("output: %d\n", n);
}
//DBG: Prints the stack with a newline
void debug(stack s){
	printf("DEBUG: [");
	for(int i=0; i<size(s); i++){
		if(i==0){ printf("%d", getItem(s, i)); }
		else{printf(",%d", getItem(s, i)); }
	}
	printf("](top)\n");
}
//TRA: Toggles trace mode on/off (off default)
//HANDLED IN MAIN

//toUpper function for instructions
