//Cade Anderson EGRE246 Project 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
//Declaring the functions that I am going to need
int* stepForest(int* grid, int* newGrid, int a, int b, float p); //Updates the current forest
int isFire(int* grid, int a, int b);
void printGrid(int* grid, int a, int b);//Prints the forest
void pause();
int countTrees(int* grid, int r, int c);

int main(int argc, char *argv[]){
	printf("Cade Anderson 9/12 \n\n");
	//Initializations
	int rows = 0;
	int cols = 0;
	int seed = 0; //Random number seed
	int p = 0; //Probability of fire spread
	FILE *fp; //Input file pointer
	char fileName[20];
	float percent = 0.0;
	int trees = 0;

	//Take input data from file and create the forest
	//Getting the filename from the command line

	if(argc > 1){
		strcpy(fileName, argv[1]);
	}else{
		//printf("Failure Reached");
		exit(EXIT_FAILURE);
	}
	fp = fopen(fileName, "r"); //Open the file for reading
	//Read first lines of file for rows, cols, seed and probability
	//Dont forget DEAL WITH FAILURE CONDITIONS p < 0 ; s < 0
	fscanf(fp, "%d", &rows);
	fscanf(fp, "%d", &cols);
	fscanf(fp, "%d", &seed);
	fscanf(fp, "%d", &p);
	int time = 0;
	if(p < 0 || seed < 0)
		exit(EXIT_FAILURE);
	srand(seed);
	float prob = p/100.0;
	//Creating the grid using rows and cols
	int* grid = (int*)malloc(rows * cols * sizeof(int));
	int* newGrid = (int*)malloc(rows * cols * sizeof(int));
	//Initializing the grid
	for(int i = 0; i < rows; i++){
		for(int j = 0; j<cols; j++){
			grid[i*cols + j] = 0;
		}
	}
	// 0 EMPTY 1 TREE 2 FIRE
	char in = 'z';
	int locX = 0, locY = 0;
	while(in != 'Q'){
		fscanf(fp, "%c", &in);
		if(in == 'A'){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j<cols; j++){
					grid[i*cols + j] = 1;
				}
			}
		}else if(in == 'E'){
			fscanf(fp, "%d", &locX);
			fscanf(fp, "%d", &locY);
			grid[(locX-1)*cols + (locY-1)] = 0;
		}else if(in == 'T'){
			fscanf(fp, "%d", &locX);
			fscanf(fp, "%d", &locY);
			grid[(locX-1)*cols + (locY-1)] = 1;
		}else if(in == 'F'){
			fscanf(fp, "%d", &locX);
			fscanf(fp, "%d", &locY);
			grid[(locX-1)*cols + (locY-1)] = 2;
		}
	}
	trees = countTrees(grid, rows, cols);
	//Printing out initial info
	printf("rows: %d\n", rows);
	printf("cols: %d\n", cols);
	printf("trees: %d\n", trees);
	printf("seed: %d\n", seed);
	printf("probability: %d\n", p);
	printf("\nTime: %d\n", time);
	printGrid(grid, rows, cols);
	printf("total burned: 0 (%.1f%)\n", percent);
	while(!isFire(grid, rows, cols)){
		// printf("%d\n", time);
		// printGrid(grid, rows, cols);
		stepForest(grid, newGrid, rows, cols, prob);
		for(int i = 0; i<rows; i++){
			for(int j=0; j<cols; j++){
				grid[i*cols+j] = newGrid[i*cols+j];
			}
		}
		// pause();
		time++;
	}
	printf("\n<<< Final Forest >>>\n");
	printf("Time: %d\n", time);
	int fTrees = countTrees(grid, rows, cols);
	printGrid(grid, rows, cols);
	printf("total burned: %d (%.1f%)\n", trees-fTrees, (float)(trees-fTrees)*100/(float)(trees));
	printf("trees left: %d", fTrees);
	//Probably going to have to print one final generation of the forest
	fclose(fp); //Closing the file
	free(grid);
	free(newGrid);
	return 0;
}

void printGrid(int* grid, int r, int c){
	//Spaces before column numbers
	printf("   ");
	//Printing out column numbers
	for(int i = 1; i<=c; i++){
		if(i%10 == 0){
			printf("%d", i/10);
		}else{
			printf(" ");
		}
	}
	printf("\n");
	//Spaced before column numbers again
	printf("   ");
	for(int i = 1; i<=c; i++){
		printf("%d", i%10);
	}
	printf("\n");
	//Print out the table lining
	printf("  ");
	printf("+");
	for(int i=0; i<c; i++){
		printf("-");
	}
	printf("+\n");
	//Printing actual forest
	for(int i = 0; i < r; i++){
		if((i+1)%10 == 0){
			printf("%d%d|", (i+1)/10, (i+1)%10);
		}else{
			printf(" %d|", (i+1)%10);
		}
		for(int j = 0; j<c; j++){
			if(grid[i*c+j] == 0){
				printf(".");
			}else if(grid[i*c+j] == 1){
				printf("T");
			}else if(grid[i*c+j] == 2){
				printf("F");
			}
		}
		if((i+1)%10 == 0){
			printf("|%d%d", (i+1)/10, (i+1)%10);
		}else{
			printf("| %d", (i+1)%10);
		}
		printf("\n");
	}
	//Print out the table lining
	printf("  ");
	printf("+");
	for(int i=0; i<c; i++){
		printf("-");
	}
	printf("+\n");
	printf("   ");
	for(int i = 1; i<=c; i++){
		printf("%d", i%10);
	}
	printf("\n");
	printf("   ");
	//Printing out column numbers
	for(int i = 1; i<=c; i++){
		if(i%10 == 0){
			printf("%d", i/10);
		}else{
			printf(" ");
		}
	}
	printf("\n");
}

void pause(){
	printf("Press enter to continue: \n");
	getchar();
}

int isFire(int* grid, int r, int c){
	int count = 0;
	for(int i=0; i<r;i++){
		for(int j=0; j<c;j++){
			if(grid[i*c+j]==2)
				count++;
		}
	}
	return (count==0);
}
int* stepForest(int* grid, int* newGrid, int r, int c, float p){
	//First implementing WITHOUT randomness
	//Setting the new grid equal to the current grid
	for(int i = 0; i<r; i++){
		for(int j=0; j<c; j++){
			newGrid[i*c+j] = grid[i*c+j];
		}
	}
	for(int i = 0; i<r; i++){
		for(int j = 0; j < c; j++){
			if(grid[i*c+j]==2)
				newGrid[i*c+j] = 0;
			if(grid[i*c+j] == 1){
				if((j-1 >= 0 && grid[i*c + (j-1)] == 2)||(j+1 < c && grid[i*c + (j+1)] == 2)||(i+1 < r && grid[(i+1)*c + j] == 2)||(i-1 >=0 && grid[(i-1)*c + j] == 2)){
					if((float)rand()/(float)(RAND_MAX) < p){
						newGrid[i*c+j] = 2;
					}
				}
			}
		}
	}
	return newGrid;
}

int countTrees(int* grid, int r, int c){
	int trees = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grid[i*c+j] == 1)
				trees++;
		}
	}
	return trees;
}
