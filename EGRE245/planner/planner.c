#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FLEN 30
#define IPLEN 50

typedef struct{
  int date;
  char description[IPLEN];
  int number;
}appointment_t;

//Modified fgets to not take the \n that was in the buffer from the date
void modfget(char inp[]){
  do{
    fgets(inp, IPLEN, stdin);
  }while(inp[0] == '\n');

}

//This is the function to write an event to the planner
void writePlanner(appointment_t* event){
  //Creating a file name and a file pointer
    char fileName[FLEN] = "planner";
    FILE *inputFile = NULL;
    //Opening the file for writing
    inputFile = fopen(fileName, "w");
    //Writing the structure data into the file
    fprintf(inputFile, "%d\n", event[0].number);
    for(int i=0; i<event[0].number; i++){
      fprintf(inputFile, "%d %s\n", event[i].date, event[i].description);
    }
    //Closing the file
    fclose(inputFile);
    inputFile = NULL;//Just some extra protection against file corruption
}

//This is the function to read the information stored in the planner
//read the file and create a structure of type appt using the info in the file
appointment_t* readPlanner(appointment_t* event){
  return event;
}

//Displays the planner
void displayPlanner(void){
  time_t tday = time(NULL);
  struct tm *tinst = localtime(&tday);
  int today = tinst->tm_mday;
  appointment_t *inst = NULL;
  inst = readPlanner(inst);
  for(int i=0; i<inst[0].number;i++){
    if(inst[i].date >= today){
        printf("%s in %d days", inst[i].description, inst[i].date-today);
    }else{
        printf("%s in %d days", inst[i].description, -(inst[i].date-today));
    }

  }
}

//This is the function to create a structure that will be passed to writePlanner
void addEvent(){
  //Dynamically creating an instance of the event
  appointment_t* event = NULL;
  event = (appointment_t*)malloc(sizeof(appointment_t));
  //Take information about event until the user is DONE
  char done[4] = "CON";
  int num = 0;
  while(strcmp(done, "DONE")){
    //Taking the date of the appt
    printf("Please enter the date of the event: \n");
    scanf("%d", &event[num].date);
    //Taking the description of the event
    printf("Please enter an event description: \n");
    modfget(event[num].description);
    num++;
    event[0].number = num;
    printf("If you are done adding, type DONE\n");
    scanf("%s", done);
    if(strcmp(done, "DONE")){
        //If the user wants to enter more events, we allocate more memory
        event = realloc(event, (num+1)*sizeof(appointment_t));
    }
  }
  //writePlanner(event) to add the event to the planner
  writePlanner(event);
  free(event);
}

int main(void){
  addEvent();
  return 0;
}
