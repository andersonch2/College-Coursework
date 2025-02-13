//Cade Anderson Project 4 11/5/2022 EGRE246
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "geometry.h"
#include "world.h"
#include "species.h"
#include "creature.h"

//Creature definition
struct creatureType{
	int id;
	species s;
	world w;
	point p;
	direction dir;
	int programCounter;
	bool isRunning;
};

//Constructors and destructors
creature newCreature(int n, species s, world w, point p, direction d){
	creature newCreature = malloc(sizeof(struct creatureType));
	newCreature->id = n;
	newCreature->s = s;
	newCreature->w = w;
	newCreature->p = p;
	newCreature->dir = d;
	newCreature->programCounter = 1;
	newCreature->isRunning = false;
	return newCreature;
}

void freeCreature(creature c){
	free(c);
}

//Setters and getters
//ID
int getId(creature c){
	return c->id;
}
void setId(creature c, int n){
	c->id = n;
}

//World
world getWorld(creature c){
	return c->w;
}
void setWorld(creature c, world wo){
	c->w = wo;
}

//Point
point getPoint(creature c){
	return c->p;
}
void setPoint(creature c, point po){
	c->p = po;
}

//Direction
direction getDirection(creature c){
	return c->dir;
}
void setDirection(creature c, direction d){
	c->dir = d;
}

//Species
species getSpecies(creature c){
	return c->s;
}
void setSpecies(creature c, species sp){
	c->s = sp;
}

//Functional methods for playing the game
int getPC(creature c){
	return c->programCounter;
}

bool isRunning(creature c){
	return c->isRunning;
}

void takeTurn(creature c){}

char* toCreatureString(creature c){
	char* string = malloc(sizeof(char)*100);
	if(strcmp(getSpeciesName(c->s), "") == 0){
		sprintf(string, "(\"\",#%d,(row:%d,col:%d),%s)", c->id, getRow(c->p),getCol(c->p),toDirectionString(c->dir));
	}else{
		sprintf(string, "(%s,#%d,(row:%d,col:%d),%s)", getSpeciesName(c->s), c->id, getRow(c->p),getCol(c->p),toDirectionString(c->dir));
	}
	return string;
}
