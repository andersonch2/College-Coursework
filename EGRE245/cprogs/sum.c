#include <stdio.h>
int fact(int n);
int main(void){
  int sum = 0, num = 0;
  while(num >= 0){
    printf("Please enter a non negative integer: ");
    scanf("%d", &num);
    if(num > -1){
      sum += num;
    }
  }
  printf("%d", sum);
  int fact = factorial(5);
  printf("%d", fact);
  return 0;
}

int factorial(int num){
  int fact = num;
  for(int i = num-1; i > 0; i--){
    fact = fact * i;
  }
  return fact;
}
