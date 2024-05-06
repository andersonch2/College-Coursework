#include <stdio.h>
#include <math.h>

int main(void){
  char name[30];
  double weight, height;
  double bmi = 0.0;
  const int conv = 703;

  printf("Please enter your name, weight and height\n");
  scanf("%s %lf %lf", name, &weight, &height);

  bmi = (weight / pow(height, 2)) * conv;

  printf("%s's BMI is %.2f\n", name, bmi);
  if(bmi < 18.5){
    printf("You are underweight\n");
  }else if(bmi < 25){
    printf("You are normal weight for your height\n");
  }else if(bmi < 30){
    printf("You are overweight\n");
  }else if(bmi < 40){
    printf("You are obese\n");
  }else{
    printf("You are MORBIDLY OBESE\n");
  }
  return 0;
}
