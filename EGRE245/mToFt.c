#include <stdio.h>

void meterToFeet(int ft, double* meter){
  *meter = ft*3.28084;
}
void swap(int* n1, int* n2){
  if(n1 > n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
  }

}
int main(){
  int n1;
  int n2;
  printf("Print two number please: ");
  scanf("%d %d", &n1, &n2);
  printf("%d %d\n", n1, n2);
  swap(&n1, &n2);
  printf("%d %d", n1, n2);
  return 0;
}
