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
}Ultra_t;

Ultra_t deCipher(Ultra_t message){
  int temp[LEN] = {0};
  //Get the cipher text from the user
  printf("Please enter the cipher text: \n");
  fgets(message.cipherText, LEN, stdin);
  //Getting the signature from the user
  printf("Please enter the signature: \n");
  //Have to iterate to length-1 because we have not snipped the \n yet
  for(int i=0; i<strlen(message.cipherText)-1; i++){
    scanf("%d", &message.signature[i]);
  }
  //Remove the \n chararcter from the string
  if(message.cipherText[strlen(message.cipherText)-1] == '\n'){
      message.cipherText[strlen(message.cipherText)-1] = '\0';
  }
  //Creating the plainText string from the signature
  for(int i=0; i<strlen(message.cipherText); i++){
      int rand = randomArray[i];
      temp[i] = message.cipherText[i]-65;
      if(message.signature[i] == 0){
          message.plainText[i] = 32;
      }else{
          //Reversing the processing from Enigma
          int sig = message.signature[i]*26;
          temp[i] = temp[i] + sig;
          temp[i] = temp[i]/rand;
          temp[i] = temp[i]+64;
          //Putting the character back into the plaintext
          message.plainText[i] = temp[i];
      }
  }
  //The next line makes sure we stop the string after the last character
  message.plainText[strlen(message.cipherText)] = '\0';
  return message;
}


int main(void){
  Ultra_t cipher;
  cipher = deCipher(cipher);
  printf("Plain Text: ");
  printf("%s\n", cipher.plainText);
  printf("Cipher Text:");
  //PRINT CIPHERTEXT AS A STRING NOT AN INTEGER ARRAY RETARD
  printf("%s\n", cipher.cipherText);
  printf("Signature: ");
  for(int i=0; i<strlen(cipher.plainText); i++){
    printf("%d ", cipher.signature[i]);
  }
  printf("\n");
  return 0;
}
