#ifndef TTT_H
#define TTT_H

#define EMPTY ' '

typedef struct btype *board;

/*
  - assume that the upper left corner of the board is square 1,1
  - all functions are undefined when passed an illegal row,col
*/

board createBoard(); // returns an empty board (all squares set to EMPTY)
void putX(board b,int row,int col); // puts an 'X' at row,col
void putO(board b,int row,int col); // puts an 'O' at row,col
char get(board b,int row,int col);  // returns value at row,col

char *toString(board b); // returns a string representation of board b;
                         // string returned does not have to be the minimum
                         // size to store the board. See sample run for format.

#endif
