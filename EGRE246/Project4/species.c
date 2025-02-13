//Cade Anderson Project 4 11/5/2022 EGRE246
#include "species.h"
#include "instruction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the species ADT
struct speciesType{
	FILE* filePtr; //File pointer
	char* fileName; //File name
	char* speciesName; //Species name
	int lines;
	instruction insList[100]; //List of instructions, max 100
};

//Constructors and destructors
species createSpecies(char* file){
	species newSpecies = malloc(sizeof(struct speciesType));
	newSpecies->filePtr = NULL;
	newSpecies->fileName = file;
	newSpecies->speciesName = "";
	newSpecies->lines = 0;
}
void freeSpecies(species s){
	free(s);
}

//Getters and setters
FILE* getFilePtr(species s){
	return s->filePtr;
}

void setFilePtr(species s, FILE* f){
	s->filePtr = f;
}

char* getFileName(species s){
	return s->fileName;
}

void setFileName(species s, char* name){
	s->fileName = name;
}

char* getSpeciesName(species s){
	return s->speciesName;
}

void setSpeciesName(species s, char* name){
	s->speciesName = name;
}
//Instruction methods
//Adds instruction to the end of the species code
void addInstruct(species s, instruction ins){
	//Basically replacing the last instruction and putting "END" after it
	s->insList[s->lines++] = ins;
}
//Set instruction n to ins in species s
void setInstruct(species s, instruction ins, int n){
	s->insList[n-1] = ins;
}

//Returns the nth instruction for species s
instruction getInstruct(species s, int n){
	return s->insList[n-1];
}

//Other functions
int getLinesOfCode(species s){
	return s->lines;
}

char* toSpeciesString(species s){
	char* string = malloc(sizeof(char)*100);
	if(strcmp(s->speciesName, "") == 0){
		sprintf(string, "(\"\",lines:%d)", s->lines);
	}else{
		sprintf(string, "(%s,lines:%d)", s->speciesName, s->lines);
	}
	return string;
}
