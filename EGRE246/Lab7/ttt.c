#include "ttt.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EMPTY ' '

struct btype{
	char grid[3][3];
};

board createBoard(){
	board b = malloc(sizeof(struct btype));
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			b->grid[i][j] = EMPTY;
		}
	}
	return b;
};

void putX(board b, int x, int y){
	b->grid[x-1][y-1] = 'X';
}

void putO(board b, int x, int y){
	b->grid[x-1][y-1] = 'O';
}

char get(board b, int x, int y){
	return b->grid[x-1][y-1];
}

char *toString(board b){
	char string[100];
	char temp[100];
	char* boardString = malloc(100*sizeof(char));

	sprintf(string, "   |   |   \n");
	for(int i=1; i<=3; i++){
		int c = 1;
		sprintf(temp, " %c | %c | %c \n", get(b, i, c), get(b, i, c+1), get(b, i, c+2));
		strcat(string, temp);
		if(i <= 2) strcat(string, "-----------\n");
	}
	strcat(string,  "   |   |   \n");
	sprintf(boardString, string);
	return boardString;
}
