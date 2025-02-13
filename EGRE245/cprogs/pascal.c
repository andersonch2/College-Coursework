#include <stdio.h>
#include <math.h>
int factorial(int n);
int ncr(int n, int r);
int main(){
  int n = 10;
  for(int i = 0; i < n; i++){
      for(int s = 0; s < n-i; s++){
        printf(" ");
      }
      for(int j = 0; j <= i; j++){
          printf("%d ", ncr(i, j));
      }
      printf("\n");
  }
  return 0;
}

int factorial(int n){
  int f = 1;
  while(n > 0){
    f = f*n;
    n--;
  }
  return f;
}
int ncr(int n, int r){
  return (factorial(n)/(factorial(n-r)*factorial(r)));
}
