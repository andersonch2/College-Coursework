#include <stdio.h>

int main(void)
{
  //Declare the variables that will be used in the program
  int id;
  float gpa;
  //Read for the input
  scanf("%d", &id);
  scanf("%f", &gpa);
  //Print the inputs with context for the user
  printf("The applicant with id %d has a GPA of %f", id, gpa);
  //Return that there was a safe execution
  return 0;
}
