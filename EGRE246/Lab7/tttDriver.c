#include <stdio.h>
#include "ttt.h"

int main(void){
  board b = createBoard();
  putX(b,1,1);
  putX(b,2,2);
  putO(b,1,2);
  putO(b,3,3);

  printf("   |   |\n");
  for(int r = 1; r <= 3; r++) {
    int c = 1;
    printf(" %c | %c | %c \n",get(b,r,c),get(b,r,c+1),get(b,r,c+2));
    if(r<3) printf("-----------\n");
  }
  printf("   |   |\n\n");

  printf("from toString:\n%s",toString(b));

  return 0;
}
