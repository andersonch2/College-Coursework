#include "string.h"
#include <stdio.h>
#include <stdlib.h>

string screate(){
	string str = malloc(sizeof(struct stringType));
	str->length = 0;
	return str;
	//We have to use sizeof(struct stringType) because
	//string is a user-defined structure stringType
}

int slen(string str){
	return str->length;
}

void printString(string s){
	for(int i=0; i<slen(s); i++){
		printf("%c", s->str[i]);
	}
}

void scopy(string s, char *cstr){
	int i = 0;
	s->length = 0;
	while(cstr[i] != '\0' && i < MAX_STRING_SIZE){
		s->str[i] = cstr[i];
		s->length++;
		i++;
	}
}
