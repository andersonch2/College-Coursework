#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* sieve(int* inList, int inSize, int n, int* outSize);

int main(void){
	int size = 0;
	int outSize = 0;
	scanf("%d ", &size);
	int num = 0;
	scanf("%d ", &num);
	//printf("%d %d", size, num);
	int* data = (int*)malloc(sizeof(int)*size);
	for(int i=0; i<size; i++){
		scanf("%d ", &data[i]);
	}
	printf("Data set size: %d\n", size);
	printf("input: \n");
	for(int i=0; i<size; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
	int* arr = sieve(data, size, num, &outSize);
	printf("List size: %d\n", outSize);
	printf("filtered list: \n");
	for(int i=0; i<outSize; i++){
		printf("%d ", arr[i]);
	}
	free(data);
	//free(outSize);
	free(arr);
	return 0;
}


int* sieve(int* inList, int inSize, int n, int* outSize){
	//int* list = malloc(sizeof(int)*inSize);
	//Go through, make count for outSize then allocate memory
	for(int i=0; i<inSize; i++){
		if(inList[i] >= n){
			(*outSize)++;
		}
	}
	int* list = malloc(sizeof(int)*(*outSize));
	int c = 0;
	for(int j=0; j<inSize; j++){
		if(inList[j] >= n){
			list[c] = inList[j];
			c++;
		}
	}
	if((*outSize) > 0){
		return list;
	}else
	return NULL;
}
