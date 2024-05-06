#include <stdio.h>
#include <math.h>

int main(void)
{
  const int minCommision = 40;
  int size = 0;
  float commission = 0;
  printf("Please enter the transaction size: \n");
  scanf("%d", &size);
  if(size <= 5000)
    commission = minCommision + 25 + 0.015*size;
  else if(size > 5000 && size <= 10000)
    commission = minCommision + 50 + 0.00075*size;
  else if(size > 10000 && size <= 20000)
      commission = minCommision + 75 + 0.00034*size;
  else if(size > 20000 && size <= 50000)
      commission = minCommision + 100 + 0.00020*size;
  else if(size > 50000 && size <= 500000)
      commission = minCommision + 150 + 0.00010*size;
  else
      commission = minCommision + 250 + 0.00005*size;
  printf("The size of the trade commission is %f", commission);
  return 0;
}
