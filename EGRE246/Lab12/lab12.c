#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1300000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int binSearch(int[], int, int, int);

int main(int arc, char* argv[]){
	int *list = malloc(sizeof(int)*SIZE);
	int in = 0, size = 0;
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");

	while(in != -1){
		fscanf(fp, "%d", &in);
		if(in != -1){list[size] = in;}
		size++;
	}

	qsort(list, size, sizeof(int), cmpfunc);
	printf("The location of 1471007 is: %d\n", binSearch(list, 1471007, 0, size));
	printf("The location of 3343708 is: %d\n", binSearch(list, 3343708, 0, size));
	printf("The location of 4878075 is: %d\n", binSearch(list, 4878075, 0, size));
	printf("The location of 3459729 is: %d\n", binSearch(list, 3459729, 0, size));
	printf("The location of 2738512 is: %d\n", binSearch(list, 2738512, 0, size));
	printf("The location of 2129333 is: %d\n", binSearch(list, 2129333, 0, size));
	printf("The location of 1054968 is: %d\n", binSearch(list, 1054968, 0, size));

	return 0;
}

int binSearch(int list[], int n, int low, int high){
	if (low>high){
		return -1;
	}
	else{
		int mid = (low+high)/2;
		if(n == list[mid]){
			return mid;
		}else if(n > list[mid]){
			return binSearch(list, n, mid+1, high);
		}else{
			return binSearch(list, n, low, mid - 1);
		}
	}
}
