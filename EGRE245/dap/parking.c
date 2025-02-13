#include <stdio.h>
#include <math.h>

int main(void){
  int zoneOverLim = 0, totOver = 0;
  int carsOver = 0, maxTime = 0, currTime = 0;
  int numZones = 4, numCars = 10;
  for(int i = 0; i < numZones; i++){
      carsOver = 0;
      scanf("%d ", &maxTime);
      for(int j = 0; j < numCars; j++){
          scanf("%d ", &currTime);
          if(currTime > maxTime){
              carsOver++;
              totOver++;
          }
      }
      if(carsOver >= 5){
        zoneOverLim++;
      }
  }
  printf("%d cars over the limit\n", totOver);
  if(zoneOverLim >= 2){
      printf("A campaign is necessary\n");
  }else{
      printf("A campaign is not necessary\n");
  }

  return 0;
}
