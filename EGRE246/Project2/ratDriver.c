#include <stdio.h>
#include <stdbool.h>
#include "rat.h"

int main(void){
	rat r1 = createRat(-4, 7);
	rat r2 = createRat(-4, -5);
	rat r3 = createRat(9, -5);
	rat r4 = createRat(0, -6);

	printf("toString(r1): %s\n", toString(norm(r1)));
	printf("toString(r2): %s\n", toString(norm(r2)));
	printf("toString(r3): %s\n", toString(norm(r3)));
	printf("toString(r4): %s\n", toString(norm(r4)));

	printf("cmp(r1, r2): %d\n", cmp(r1, r2));
	printf("cmp(r1, r3): %d\n", cmp(r1, r3));
	printf("cmp(r1, r4): %d\n", cmp(r1, r4));
	return 0;
}
