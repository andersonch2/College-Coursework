#include "intSet.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//CHECKLIST
	// createSet(): DONE
	// destroySet(): DONE
	// clear():	DONE
	// card():	DONE
	// equals():	DONE
	// contains():	DONE
	// largest():	DONE
	// smallest():	DONE
	// add()	DONE
	// remove()	DONE
	// union() idk atp bro
	// intersect()	DONE
	// diff()		DONE
	// isEmpty()	DONE
	// toArray()	DONE
	// toString()	DONE

struct intsetType{
	int *list;
	int size;
	bool isEmpty;
};

//Creates a set at runtime
intSet createSet(){
	intSet set = malloc(sizeof(struct intsetType));
	set->size = 0;
	set->isEmpty = true;
	return set;
}


//Frees the memory associated with its set
void destroySet(intSet set){
	free(set->list);
	free(set);
}

//Clears the set to empty
//set = [1, 2, 3] --> set = []
void clear(intSet set){
	set->size = 0;
	set->list = malloc(sizeof(int));
	set->isEmpty = true;
}

//Cardinality is the size of a set, and we cannot have duplicate items in the set
int card(intSet set){
	return set->size;
}
bool equals(intSet set1, intSet set2){
	if(card(set1) == card(set2)){
		for(int i=0; i<set1->size; i++){
			if(!(contains(set2, set1->list[i]))){
				return false;
			}
		}
		return true;
	}else
		return false;
}

bool contains(intSet set, int n){
	if(!(isEmpty(set))){
		for(int i=0; i<set->size; i++){
			if(set->list[i] == n){
				return true;
			}
		}
		return false;
	}else{
		return false;
	}
}
int largest(intSet set){
	if(!(isEmpty(set))){
		int max = 0;
		for(int i=0; i<set->size; i++){
			if(set->list[i] > max){
				max = set->list[i];
			}
		}
		return max;
	}else{
		printf("Error: cannot find largest item in empty set\n");
		return 1;
	}
}
int smallest(intSet set){
	if(!(isEmpty(set))){
		int min = largest(set);
		for(int i=0; i<set->size; i++){
			if(set->list[i] < min){
				min = set->list[i];
			}
		}
		return min;
	}else{
		printf("Error: cannot find smallest item in empty set\n");
		return -1;
	}
}

void add(intSet set, int n){
	if(!(contains(set, n))){
		int* l = set->list;
		for(int i=0; i<set->size; i++){
			l[i] = set->list[i];
		}
		set->list = (int*)malloc((set->size++)*sizeof(int));
		for(int i=0; i<set->size-1; i++){
			set->list[i] = l[i];
		}
		set->list[set->size-1] = n;
		set->isEmpty = false;
	}
}
//Remove could definitely be redone lol
void remove_(intSet set, int n){
	int loc = 0;
	if(contains(set, n)){
		int l[set->size];
		for(int i=0; i<set->size; i++){
			if(!(set->list[i] == n)){
				l[i] = set->list[i];
			}
			if(set->list[i] == n){
				loc = i;
			}
		}
		set->list = (int*)malloc((set->size--)*sizeof(int));
		for(int i=0; i<set->size+1; i++){
			if(i < loc){
				set->list[i] = l[i];
			}
			if(i > loc){
				set->list[i-1] = l[i];
			}
		}
		if(set->size == 0){
			set->isEmpty = true;
		}
	}
}

intSet union_(intSet s1, intSet s2){
	intSet result = createSet();
	int c = 0;
	for(int i=0; i<s1->size; i++){
		add(result, s1->list[i]);
	}
	for(int i=0; i<s2->size; i++){
		if(!(contains(s1, s2->list[i]))){
			// printf("DEBUG BEFORE ADD IN LOOP: %s\n", toString(result));
			printf("");
			add(result, s2->list[i]);
			c++;
			// printf("DEBUG IN LOOP: %s\n", toString(result));
		}
	}
	// printf("DEBUG BEFORE RETURN: %s\n", toString(result));
	return result;
}

intSet intersect(intSet set1, intSet set2){
	intSet result = createSet();
	for(int i=0; i<set1->size; i++){
		if(contains(set2, set1->list[i])){
			add(result, set1->list[i]);
		}
	}
	return result;
}

intSet diff(intSet set, intSet set2){
	intSet result = createSet();
	for(int i=0; i<set->size; i++){
		if(!(contains(set2, set->list[i]))){
			add(result, set->list[i]);
		}
	}
	return result;
}
//Can probably use this to avoid errors
bool isEmpty(intSet set){
	return set->isEmpty;
}

int *toArray(intSet set){
	//copying the array
	if(!(isEmpty(set))){
		int* l = malloc(set->size*sizeof(int));
		for(int i=0; i<set->size; i++){
			l[i] = set->list[i];
		}
		//sorting the array
		int temp = 0;
		for(int i=0; i<set->size;i++){
			for(int j=0; j<set->size-i; j++){
				if(l[i] > l[i+1]){
					temp = l[i];
					l[i] = l[i+1];
					l[i+1] = temp;
				}
			}
		}
		return l;
	}else{ //Returns NULL if the list is empty
		return NULL;
	}
}

char* toString(intSet set){
	if(!isEmpty(set)){
		int* list = toArray(set);
		char* str = malloc((4*(set->size)+2)*sizeof(char));
		char temp[20];
		strcpy(str, "{");
		for(int i=0; i<set->size-1; i++){
			sprintf(temp, "%d,", set->list[i]);
			strcat(str, temp);
		}
		sprintf(temp, "%d}", set->list[set->size-1]);
		strcat(str, temp);
		return str;
	}else{
		return "{}";
	}
}
