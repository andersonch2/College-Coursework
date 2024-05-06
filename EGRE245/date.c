#include <stdio.h>
#include <math.h>

int main(void){
  int d, test;
  printf("Please enter the day of the month the docment was dated: ");
  scanf("%d", &d);
  if(d < 10){
    test = d % 10;
  }else
    test = 5;
  switch(test){
    case 1:
      printf("Dated this the %dst of February, 2022", d);
      break;
    case 2:
      printf("Dated this the %dnd of February, 2022", d);
      break;
    case 3:
      printf("Dated this the %drd of February, 2022", d);
      break;
    case 4: case 5: case 6: case 7: case 8: case 9: case 0:
      printf("Dated this the %dth of February, 2022", d);
      break;
    default:
      printf("Invalid");
      break;
  }
  return 0;
}
