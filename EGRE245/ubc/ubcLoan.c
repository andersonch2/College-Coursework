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

  int y = 0;
  int m = 0;
  float p = 0, r = 0, mp = 0;

  printf("Please input your principal loan payment: \n");
  scanf("%f", &p);
  printf("Please input your monthly payment: \n");
  fflush(stdout);
  scanf("%f", &mp);
  //Compute the total repayment amount
  r = p*1.5;
  //Extract the months and years from the repayment amount
  m = (int) ceil(r/mp);
  y = m/12;
  m = m % 12;
  //Return the repayment time to the user
  printf("It takes %d years and %d months to repay the loan\n", y, m);
  return(0);
}
