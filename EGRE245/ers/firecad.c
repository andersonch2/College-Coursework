#include <stdio.h>
#include <math.h>
float distance(float x1, float y1, float x2, float y2);

int main(void){
  //Constants, information about each base
  const float Bx = 69.0;
  const float By = 36.0;
  const float Cx = 89.0;
  const float Cy = 37.0;
  const float Ex = 79.0;
  const float Ey = 53.0;
  //Inputs, two floats(x and y) for coordinates of emergency location
  //And a character for the type of station, A or B
  char cat;
  float x, y;
  printf("Please input your emergency location and category of station: ");
  scanf("%f %f %c", &x, &y, &cat);
  //Check validity of the Inputs
  if(cat == 'A' || cat == 'B'){
    float distB = distance(x, y, Bx, By);
    float distC = distance(x, y, Cx, Cy);
    float distE = distance(x, y, Ex, Ey);
    int timeB = (int)ceil((distB/20.0)*60);
    int timeC = (int)ceil((distC/15.7)*60);
    int timeE = (int)ceil((distE/17.5)*60);
    if(cat == 'A'){
        //Compare distances B and E
        if(timeB < timeE){
            if(distB < 15){
                printf("Brent dispatch. ETA %d minutes", timeB);
            }else if(distE < 15){
                printf("Enfield dispatch. ETA %d minutes", timeE);
            }else{
                printf("No category A units in range");
            }
        }else if(distE < 15){
            printf("Enfield dispatch. ETA %d minutes", timeE);
        }else{
            printf("No category A units in range");
        }
    }else{
      //Check if the C distance is within range
      if(distC < 15){
          printf("Camden dispatch. ETA %d minutes", timeC);
      }else{
          printf("No category B units in range");
      }
    }
  }else{
    printf("Invalid category");
  }
  //float d = distance(0, 0, 3, 4);
  //printf("%f", d);
  //Return info back to the user
  return 0;
}

//Maybe make a function for  linear distance
float distance(float x1, float y1, float x2, float y2){
  float dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
  return dist;
}
