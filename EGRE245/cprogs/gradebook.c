#include <stdio.h>

typedef struct{
  float attendance;
  float reading;
  float program;
  float midterm;
  float final;
}Score_t;

Score_t inputInfo(void){
  Score_t grades;
  printf("Please input the grades for the student: \n");
  scanf("%f", &grades.attendance);
  scanf("%f", &grades.reading);
  scanf("%f", &grades.program);
  scanf("%f", &grades.midterm);
  scanf("%f", &grades.final);
  return grades;
}
float gradeTotal(Score_t max, Score_t weights, Score_t scores){
  float grade = (scores.attendance*weights.attendance)/(max.attendance);
  grade += (scores.reading*weights.reading)/(max.reading);
  grade += (scores.program*weights.program)/(max.program);
  grade += (scores.midterm*weights.midterm)/(max.midterm);
  grade += (scores.final*weights.final)/(max.final);
  return grade;
}
int main(void){
  const Score_t maxScores = {140, 120, 400, 50, 100};
  const Score_t weights = {5, 20, 25, 20, 30};
  Score_t studentScore = inputInfo();
  float final = gradeTotal(maxScores, weights, studentScore);
  printf("Your final grade is %f", final);
  return 0;
}
