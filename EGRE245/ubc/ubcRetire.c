#include <stdio.h>
#include <math.h>

int main(void)
{
  printf("  ,_____ ,         /$$   /$$ /$$$$$$$   /$$$$$$\n");
  printf("  ,._ ,_. 7\\      | $$  | $$| $$    $$ /$$    $$\n");
  printf(" j `-'     /      | $$  | $$| $$    $$| $$  \n");
  printf(" |o_, o    \\      | $$  | $$| $$$$$$$ | $$      \n");
  printf(".`_y_`-,'   !     | $$  | $$| $$    $$| $$      \n");
  printf("|/   `, `._ `-,   | $$  | $$| $$    $$| $$    $$\n");
  printf("|_     \\   _.'*\\  |  $$$$$$/| $$$$$$$/|  $$$$$$/\n");
  printf("  >--,-'`-'*_*'``  \\______/ |_______/  \\______/       \n");
  printf("            \"Our Barker Guards Your Future\"\n");

  float d = 0, i = 0, t = 0;
  int y = 0, m = 0;
  printf("Please input your desired savings amount: \n");
  scanf("%f", &d);
  printf("Please input the amount you are willing to invest: \n");
  fflush(stdout);
  scanf("%f", &i);

  //Compute savings time, might have to use a logarithm
  t = (log(d) - log(i))/ log(1+ 0.05);
  //Extract the years and months from the total time
  y = (int) (t);
  m = (int) (ceil((t-y) * 12));
  //Return the savings time back to the user
  printf("Your desired amount is reached in %d years and %d months", y, m);
  return 0;
}
