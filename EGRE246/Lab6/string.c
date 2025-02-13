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

int scmp(string s1, string s2){
	//Go to the length of the shorter string
	//Ternary operator
	for(int i = 0; i<slen(s1); i++){
		if(s1->str[i] < s2->str[i]){
			return -1;
		}else if(s1->str[i] > s2->str[i]){
			return 1;
		}
	}
	return 0;
}

string scat(string dest, string src){
	string newString = screate();
	scopy(newString, dest->str);
	// printf("DEBUG:\n");
	for(int i = slen(dest); i < slen(dest) + slen(src); i++){
		newString->str[i] = src->str[i - slen(dest)];
		// printString(newString);
		// printf("\n");
	}
	newString->length = slen(dest) + slen(src);
	return newString;
}

string sToUpper(string s1){
	//between 97 and 122
	for(int i=0; i<slen(s1); i++){
		if(s1->str[i] >= 97 && s1->str[i] <= 122){
			s1->str[i] = s1->str[i]-32;
		}
	}
	return s1;
}

string sToLower(string s1){
	//Between 65 and 90
	for(int i=0; i<slen(s1); i++){
		if(s1->str[i] >= 65 && s1->str[i] <= 90){
			s1->str[i] = s1->str[i]+32;
		}
	}
	return s1;
}
