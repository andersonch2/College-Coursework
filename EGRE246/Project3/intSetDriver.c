#include "intSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	intSet set = createSet();
	intSet set2 = createSet();
	//Creating the sets to test the functions
	add(set, 1);
	add(set, 2);
	add(set, 3);
	add(set, 4);
	add(set2, 1);
	add(set2, 2);
	add(set2, 5);
	add(set2, 6);
	printf("Set 1: %s\n", toString(set));
	printf("Set 2: %s\n", toString(set2));
	printf("%d %d\n", card(set), card(set2));
	//printf("Union: %s\n", toString(union_(set, set2)));
	printf("Difference: %s\n", toString(diff(set, set2)));
	printf("Intersection: %s\n", toString(intersect(set, set2)));
	clear(set);
	printf("Cleared set: %s", toString(set));
}
