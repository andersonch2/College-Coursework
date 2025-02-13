#include <stdio.h>
#include <string.h>
#define LEN 50
int randomArray[LEN] =
    {240,248,124,190,95,175,87,171,213,234,117,186,221,238,119,59,157,78,39,147,73,164,
     210,233,244,250,125,190,223,111,55,27,141,70,35,17,136,196,98,177,88,172,214,107,
     181,218,237,246,123,189};

typedef struct{
  char plainText[LEN];
  char cipherText[LEN];
  int signature[LEN];
}Enigma_t;

Enigma_t cipherFunction(Enigma_t input){
  int temp[LEN];
  //Taking the input from the user
  printf("Please input the plain text: \n");
  fgets(input.plainText, LEN, stdin);
  //Removing the newline character from the end of the array
  if(input.plainText[strlen(input.plainText)-1] == '\n'){
      input.plainText[strlen(input.plainText)-1] = '\0';
  }
  //Character processing
  for(int i=0; i<strlen(input.plainText); i++){
      temp[i] = input.plainText[i]-64; //subtract char by 64
      temp[i] *= randomArray[i]; //nult by rand randomArray
      //HANDLE THE SIGNATURE
      if(input.plainText[i] == ' '){
        input.signature[i] = 0;
      }else{
        input.signature[i] = temp[i]/26;
      }
      //ADD SOMETHING TO THE CIPHERTEXT EVERYTIME
      int mod = temp[i]%26;
      input.cipherText[i] = mod+65;
  }
  //This next line makes sure that we stop the string after the last character
  input.cipherText[strlen(input.plainText)] = '\0';
  return input;
}
//OUTPUT IS FORMATTED CORRECTLY
int main(void){
  Enigma_t message;
  message = cipherFunction(message);
  printf("Plain Text: ");
  printf("%s\n", message.plainText);
  printf("Cipher Text:");
  //PRINT CIPHERTEXT AS A STRING NOT AN INTEGER ARRAY RETARD
  printf("%s\n", message.cipherText);
  printf("Signature: ");
  for(int i=0; i<strlen(message.plainText); i++){
    printf("%d ", message.signature[i]);
  }
  printf("\n");
  return 0;
}
