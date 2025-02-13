#include <stdio.h>
#include <stdlib.h>

double* great(double* n1, double* n2){
  //We put parentheses around the dereferenced pointer to make sure it is known
  //that the current usage is for a value, not an address
  if((*n1)>(*n2)){
      //We do not dereference the pointer when returning it because the return
      //type of the function is a pointer
      return n1;
  }
  return n2;
}
int main(void){
  double pi = 22.0/7.0;
  double tau = 44.0/7.0;
  //Creating and initializing a pointer
  double* piPtr = NULL;
  double* tauPtr = NULL;
  //Assigning an address to the pointer
  piPtr = &pi;
  tauPtr = &tau;
  //Manipulate (Read and Write) the value in the address
  //We do not need an & in front of piPtr, because it is already assigned to --
  //an address
  scanf("%lf", piPtr);
  //The asterisk in front of piPtr dereferences it and allows us to use the --
  //Value at the address
  printf("The new PI: %lf\n", (*piPtr));
  //Pass the pointer and recieve a pointer
  //The benefit to passing pointers is that we can preserve the value of the
  //  entities that are passed. If we pass variables, whatever happens within the
  //  function is lost.
  double* greaterGreek = great(piPtr, &tau);
  printf("%lf is the greater greek", (*greaterGreek));
  //Create and remove dynamic memory using pointers(malloc, calloc, realloc, free)
  //Here, we have allocated memory for a double at the address of heapPi
  double* heapPi = (double*)malloc(sizeof(double));
  double* heapTau = (double*)malloc(sizeof(double));
  //Now, we give a value to the pointers just initialized
  //Again, we adopt the notation of parentheses around a dereferenced pointer
  (*heapPi) = 22.0/7.0;
  (*heapTau) = 44.0/7.0;
  //Here, we are creating an array of pointers
  //We want two double values in it, so we allocate memory equal to the memory
  //  required for two doubles, hence the 2*sizeof(double)
  double* greatGreek = (double*)malloc(2*sizeof(double));
  greatGreek[0] = *heapPi;
  greatGreek[1] = *heapTau;
  //We do not need & in front of heapPi and heapTau because they are pointers
  greatGreek = great(heapPi, heapTau);
  free(heapPi);
  free(heapTau);
  //Setting greaGreek to NULL prevent a double free error
  //The double free error is when we try to free something pointing to memory
  //  that has already been freed(invalid memory).
  greatGreek = NULL;
  free(greatGreek);
  return 0;
}
