#include <stdio.h>
#include <math.h>
double pi = 22.0/7.0;
//Declaring the function
double distance(double, double, double, double);

int main(void){
  //Constants - Locations of bases
  const double latA = 35.00;
  const double latB = 38.00;
  const double latC = 32.00;
  const double longA = 80.00;
  const double longB = 78.00;
  const double longC = 82.00;
  //Inputs - 2 floats for latitude and longitude
  printf("Please input your current latitude and longitude: ");
  double latE, longE;
  scanf("%lf %lf", &latE, &longE);
  //Check inputs for validity
  if(latE >= 0 && longE >= 0){
      //Finding the distances of all three bases, to compare
      double distA = distance(latE, longE, latA, longA);
      double distB = distance(latE, longE, latB, longB);
      double distC = distance(latE, longE, latC, longC);
      //Comparing the distances
      if(distA < distB){
          if(distA < distC){
            //A is closest
            printf("The nearest airbase is Aberport with a distance of %.2lf nautical miles", distA);
          }else{
            //C is closest
            printf("The nearest airbase is Cosford with a distance of %.2lf nautical miles", distC);
          }
      }else if(distB < distC){
          //B is closest
          printf("The nearest airbase is Benson with a distance of %.2lf nautical miles", distB);
      }else{
          //C is closest
          printf("The nearest airbase is Cosford with a distance of %.2lf nautical miles", distC);
      }
  }else{
      printf("The emergency location is out of response range");
  }
  //double d = distance(10.0, 10.0, latB, longB);
  //printf("%lf", d);
  //Return distance to the nearest base
  return 0;
}

double distance(double lat1, double long1, double lat2, double long2){
  //Convert the inputs into radians
  lat1 = (lat1*pi)/180.00;
  lat2 = (lat2*pi)/180.00;
  long1 = (long1*pi)/180.00;
  long2 = (long2*pi)/180.00;
  //Input the great circle distance
  double dist = 2*asin(sqrt(pow(sin(0.5*(lat1-lat2)),2) +  cos(lat1) *   cos(lat2)   *   pow(sin(0.5*(long1-long2)), 2) ));
  return (dist*180.0*60.0)/pi;
}
