#include <stdio.h>
#include <math.h>

int main(void)
{
  const int dist = 2916;
  float speed = 0, days = 0, hours = 0, mins = 0;
  printf("Please enter your average speed in mph: ");
  scanf("%f", &speed);
  hours = dist/speed;
  days = (int) hours / 24;
  mins = ceil((hours - (int)(hours))*60);
  hours = hours - days*24;
  printf("Your driving time took %f days, %f hours and %f minutes.", days, hours, mins);

  return 0;
}
