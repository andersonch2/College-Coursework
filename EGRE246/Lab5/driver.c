#include <stdio.h>
#include "string.h"

int main(void){
	string s1 = screate();
	scopy(s1, "hi mom");
	printf("s1 length: %d\n", slen(s1));
	printString(s1);
	printf("\n");
	string s2 = screate();
	scopy(s2, "Lab5 is cool\n");
	printString(s2);
	scopy(s2, "Hello World!");
	printf("%d\n", slen(s2));
	printString(s2);
	return 0;
}
