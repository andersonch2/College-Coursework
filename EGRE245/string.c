#include <stdio.h>
#include <string.h>

int main(void){
  char sentence[100];
  char input[100];
  while((strlen(sentence) < 100) && (strcmp(input, "ABCD") != 0)){
    scanf("%s", input);
    strcat(sentence, input);
    printf("%d", (int)(strlen(sentence)));
  }
  return 0;
}
