#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 50
const char input[LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char output[LEN] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

typedef struct{
  char message[LEN];
  char encrypted[LEN];
}rot_t;


int main(void){

  return 0;
}
