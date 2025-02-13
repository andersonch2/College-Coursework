#include <stdio.h>
#include <stdbool.h>
#include "intSet.h"

int main(void) {

  intSet is2,is1;

  is1 = createSet(); is2 = createSet();
  clear(is1);
  card(is1);
  equals(is1,is2);
  contains(is1,100);
  remove_(is1,100);
  add(is1,100);
  largest(is1);
  smallest(is1);
  union_(is1,is2);
  intersect(is1,is2);
  diff(is1,is2);
  isEmpty(is1);
  toArray(is1);
  toString(is1);
  destroySet(is1);
  printf("=== program compiled and ran ok ===\n");
  return 0;
}
