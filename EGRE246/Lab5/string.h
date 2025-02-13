#ifndef STRING_H
#define STRING_H

#define MAX_STRING_SIZE 128 // arbitrary

struct stringType {
	// your definitions go here (you will only need 2 fields - one
	// to keep track of the length, the other a char array of
	// MAX_STRING_SIZE length.
	int length;
	char str[MAX_STRING_SIZE];
};

typedef struct stringType *string;

string screate();
void   scopy(string,char *);
int    slen(string);
void   printString(string);

#endif
