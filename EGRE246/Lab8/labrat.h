#include <stdbool.h>

#ifndef LABRAT_H
#define LABRAT_H

typedef struct rtype *rat;

rat createRat(int,int); // creates and returns a rat number

rat norm(const rat);   // returns normalized number

int getNum(const rat);  // returns numerator of rat
void setNum(rat,int);   // sets numerator of rat

int getDenom(const rat); // returns denominator of rat
void setDenom(rat,int d);  // sets denominator; d can be 0!

rat inverse(const rat); // returns argument inverted

bool wellFormed(const rat); // returns true if number is legal, false otherwise

char *toString(const rat); // returns string representation of argument

#endif

