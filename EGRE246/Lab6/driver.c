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
	scopy(s2, "HELLO World!");
	printf("%d\n", slen(s2));
	printString(s2);

	//Calls to new functions
	printf("%d\n", scmp(s2, s1));
	printString(scat(s1, s2));
	printf("\n");
	printString(sToUpper(s1));
	printf("\n");
	printString(sToLower(s2));


	return 0;
}
