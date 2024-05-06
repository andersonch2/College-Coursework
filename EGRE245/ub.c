#include <stdio.h>
#include <math.h>

int main(void){
  int numAdults, numChild , sStage, eStage;
  const float aFare = 3.5;
  const float cFare = 1.5;
  float fare = 0.0;
  printf("Please enter the number of adults and children: \n");
  scanf("%d %d", &numAdults, &numChild);
  if(numChild > 0 && numAdults > 0){
    printf("Please enter the stage you entered on and the stage you left on: \n");
    scanf("%d %d", &sStage, &eStage);
    if(fabs(sStage - eStage) != 0){
        fare = ( (aFare * numAdults) + (cFare * numChild) ) * fabs(sStage - eStage);
    }else
        fare = 1;
  }else
    printf("You are not allowed to have negative people\n");
  printf("Your fare is: %.2lf", fare);
  return 0;
}
