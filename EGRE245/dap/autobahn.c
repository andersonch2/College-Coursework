#include <stdio.h>

int main(void){
  int days = 7, zones = 4;
  int tempOver = 0, tempUnder = 0;
  int dayTotal = 0, dayOver = 0;
  int daysOver = 0, zonesOver = 0;
  float ratio = 0, dayRatio = 0;
  for(int i = 0; i < days; i++){
    for(int j = 0; j < zones; j++){
        scanf("%d ", &tempUnder);
        scanf("%d ", &tempOver);
        //printf("%d %d \n", tempOver, tempUnder);
        ratio = 100*((float)(tempOver)/(tempOver + tempUnder));
        if(ratio >= 25){
            zonesOver++;
        }
        dayTotal = dayTotal + tempOver + tempUnder;
        dayOver = dayOver + tempOver;
    }
    dayRatio = 100*((float)(dayOver)/dayTotal);
    if(dayRatio >= 25){
        daysOver++;
    }
  }
  printf("%d zones over 25%% limit\n", zonesOver);
  if(daysOver >= 3){
      printf("Initiate pilot program");
  }else{
      printf("Pilot program not required");
  }
  return 0;
}
