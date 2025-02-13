//Cade Anderson EGRE246
//Project 2
//10/5/2022

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "labrat.h"

struct rtype {
  int n,d; // numerator, denominator
};

rat createRat(int num, int den){
	if(den != 0){
		rat r = malloc(sizeof(struct rtype));
		r->n = num;
		r->d = den;
	return r;
	}else{
		printf("ERROR: denominator of 0 is not allowed\n");
		exit(EXIT_FAILURE);
	}
}

//GCD function to use for the reduce function
static int gcd(int a, int b){
	int temp;
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
rat norm(rat r1){
	if(wellFormed(r1)){
		rat rnorm = malloc(sizeof(struct rtype));
		if(r1->n == 0){
			rnorm->n = 0;
			rnorm->d = 1;
		}else if(r1->d < 0){
			rnorm->n = (-1)*(r1->n);
			rnorm->d = (-1)*(r1->d);
		}else{
			rnorm->n = r1->n;
			rnorm->d = r1->d;
		}
		return rnorm;
	}else{
		printf("ERROR: can only normalize well formed numbers\n");
		exit(EXIT_FAILURE);
	}
}

int getNum(rat r){ return r->n; }
void setNum(rat r, int n){ r->n = n; }

int getDenom(rat r){ return r->d; }
void setDenom(rat r, int d){ r->d = d; }

rat reduce(rat r1){
	if(wellFormed(r1)){
		int g = gcd(r1->n, r1->d);
		int rn = (r1->n)/g;
		int rd = (r1->d)/g;
		return createRat(rn, rd);
	}else{
		printf("ERROR: Can only reduce a well formed number\n");
		exit(EXIT_FAILURE);
	}
}

int cmp(rat r1, rat r2){
	//r1 < r2 return -1
	//r1 == r2 return 0
	//r1 > r2 return 1
	if(wellFormed(r1) && wellFormed(r2)){
		if((r1->n)*(r2->d) < (r2->n)*(r1->d))
			return -1;
		else if((r1->n)*(r2->d) == (r2->n)*(r1->d))
			return 0;
		else
			return 1;
	}else{
		printf("ERROR: Can only compare well formed rational numbers\n");
		exit(EXIT_FAILURE);
	}
}

char* toString(rat r){
	char tempString[20];
	sprintf(tempString, "%d/%d", r->n, r->d);
	char* rString = malloc(strlen(tempString)*sizeof(char));
	sprintf(rString, tempString);
	return rString;
}

bool wellFormed(rat r){
	return(!(r->d == 0));
}
//Operations on a rat type
rat inverse(rat r1){
	int n1 = r1->d;
	int d1 = r1->n;
	return createRat(n1, d1);
}

//Mathematical Operations: add, sub, mul, divide
//All of these can only work if BOTH inputs are well formed
//Make sure to reduce and normalize the results of these operations
rat add(rat r1, rat r2){
	int rnum = 0, rden = 0;
	if(wellFormed(r1) && wellFormed(r2)){
		rnum = (r1->n)*(r2->d) + (r1->d)*(r2->n);
		rden = (r1->d)*(r2->d);
		rat rsum = createRat(rnum, rden);
		rsum = reduce(rsum);
		rsum = norm(rsum);
		return rsum;
	}else{
		printf("ERROR: can only add well formed rational numbers\n");
		exit(EXIT_FAILURE);
	}
}
rat sub(rat r1, rat r2){
	int rnum = 0, rden = 0;
	if(wellFormed(r1) && wellFormed(r2)){
		rnum = (r1->n)*(r2->d) - (r1->d)*(r2->n);
		rden = (r1->d)*(r2->d);
		rat rdiff = createRat(rnum, rden);
		rdiff = reduce(rdiff);
		rdiff = norm(rdiff);
		return rdiff;
	}else{
		printf("ERROR: can only subtract well formed rational numbers\n");
		exit(EXIT_FAILURE);
	}
}
rat mul(rat r1, rat r2){
	if(wellFormed(r1) && wellFormed(r2)){
		int rn = (r1->n)*(r2->n);
		int rd = (r1->d)*(r2->d);
		rat r = createRat(rn, rd);
		r = reduce(r);
		r = norm(r);
		return r;
	}else{
		printf("ERROR: can only multiply well formed rational numbers\n");
		exit(EXIT_FAILURE);
	}
}
rat divide(rat r1, rat r2){
	if(wellFormed(r1) && wellFormed(r2) && r2->n != 0){
		int rn = (r1->n)*(r2->d);
		int rd = (r1->d)*(r2->n);
		rat r = createRat(rn, rd);
		r = reduce(r);
		r = norm(r);
		return r;
	}else{
		printf("ERROR: can only divide well formed and non zero rational numbers\n");
		exit(EXIT_FAILURE);
	}
}
