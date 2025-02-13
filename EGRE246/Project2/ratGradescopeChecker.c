#include <stdio.h>
#include "rat.h"

int main(void) {
  rat r1,r2;
  r1 = createRat(2,3); r2 = createRat(3,4);
  norm(r1);
  reduce(r1);
  cmp(r1,r2);
  add(r1,r2);
  sub(r1,r2);
  mul(r1,r2);
  divide(r1,r2);
  inverse(r1);
  wellFormed(r1);
  toString(r1);
  printf("test run of checker program ok\n");
 return 0;

}
