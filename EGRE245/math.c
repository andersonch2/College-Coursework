#include <stdio.h>

int main(void)
{
  int n1, d1, n2, d2;
  printf("Please input the numerator and denominator of two fractions: \n");
  scanf("%d", &n1);
  scanf("%d", &d1);
  fflush(stdout);
  scanf("%d", &n2);
  scanf("%d", &d2);
  printf("Your two fractions are %d/%d and %d/%d\n", n1, d1, n2, d2);
  printf("Their sum is %d/%d\n", n1*d2+n2*d1, d1*d2);
  return 0;
}
