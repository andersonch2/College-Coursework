/* to compile:
     gcc proj3xxxx.cpp isetprojGrader.c
   to compile and remove TEST3, TEST4:
     gcc proj3xxxx.cpp isetprojGrader.c -DTEST3 -DTEST4
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "intSet.h"

#define NUMTESTS 40

#ifdef ALLFAIL
// set to cause all tests to fail
#include "ALLFAIL.h"
#endif


char *tostring(int n) {
  char s[20];
  snprintf(s,20,"%d",n);
  char *res = malloc(sizeof(strlen(s))+1);
  strcpy(res,s);
  return res;
}

int main(void) {
  intSet s1,s2,res;

  int t,numWrong=0;
  int c=0;
  bool f[NUMTESTS] = { 0 };

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST1
  s1 = createSet();
  printf("%s",(t=isEmpty(s1))?"true":"false");
  printf("\t\t<== true\t\t[isEmpty]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[1] = true; }
#else
  numWrong++; f[1] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST2
  s1 = createSet();
  add(s1,5);
  printf("%s",(t=isEmpty(s1))?"true":"false");
  printf("\t\t<== false\t\t[add,isEmpty]");
  if (t!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST3
  printf("%d",t=card(s1));
  printf("\t\t\t<== 1\t\t\t[card]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[1] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");


  printf("%2d: ",++c);
#ifndef TEST4
  clear(s1);
  printf("%d",t=card(s1));
  printf("\t\t\t<== 0\t\t\t[card,clear]");
  if (t!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST5
  for (int i = 1; i <= 25; i++) add(s1,i);
  printf("%d",t=card(s1));
  printf("\t\t\t<== 25\t\t\t[add,card]");
  if (t!=25) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST6
  printf("%s",(t=contains(s1,2))?"true":"false");
  printf("\t\t<== true\t\t[contains]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST7
  printf("%s",(t=contains(s1,999))?"true":"false");
  printf("\t\t<== false\t\t[contains]");
  if (t!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST8
  printf("%d",(t=largest(s1)));
  printf("\t\t\t<== 25\t\t\t[largest]");
  if (t!=25) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST9
  printf("%d",(t=smallest(s1)));
  printf("\t\t\t<== 1\t\t\t[smallest]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST10
  clear(s1);
  for (int i = 1; i <= 10000; i++) add(s1,i);
  printf("%d",(t=card(s1)));
  printf("\t\t<== 10000\t\t[add,card]");
  if (t!=10000) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST11
  remove_(s1,9000);
  printf("%d",(t=card(s1)));
  printf("\t\t<== 9999\t\t[card,remove]");
  if (t!=9999) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST12
  printf("%s",(t=contains(s1,9000))?"true":"false");
  printf("\t\t<== false\t\t[contains]");
  if (t!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST13
  remove_(s1,9000);
  printf("%d",(t=card(s1)));
  printf("\t\t<== 9999\t\t[card,remove]");
  if (t!=9999) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST14
  for (int i = 1; i <= 15000; i++) remove_(s1,i);
  printf("%s",(t=isEmpty(s1))?"true":"false");
  printf("\t\t<== true\t\t[isEmpty,remove]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST15
  clear(s1);
  s2 = createSet();
  printf("%s",(t=equals(s1,s2))?"true":"false");
  printf("\t\t<== true\t\t[equals]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST16
  add(s1,2); add(s1,10); add(s1,25);
  add(s2,10); add(s2,25); add(s2,2);
  for (int i=1; i <= 100; i++) add(s2,2);
  printf("%s",(t=equals(s1,s2))?"true":"false");
  printf("\t\t<== true\t\t[add,equals]");
  if (t!=1) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST17
  add(s2,100);
  printf("%s",(t=equals(s1,s2))?"true":"false");
  printf("\t\t<== false\t\t[add,equals]");
  if (t!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  char *s;
  printf("%2d: ",++c);
#ifndef TEST18
  clear(s1);
  printf("\"%s\"",(s=toString(s1)));
  printf("\t\t<== \"{}\"\t\t[clear,toString]");
  if (strcmp(s,"{}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST19
  clear(s1);
  for (int i = 1; i <= 4; i++) add(s1,i);
  printf("\"%s\"",(s=toString(s1)));
  printf("\t\t<== \"{1,2,3,4}\"\t\t[add,clear,toString]");
  if (strcmp(s,"{1,2,3,4}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST20
  clear(s2);
  for (int i = 3; i <= 6; i++) add(s2,i);
  printf("\"%s\"",s=toString(union_(s1,s2)));;
  printf("\t<== \"{1,2,3,4,5,6}\"\t[add,toString,union]");
  if (strcmp(s,"{1,2,3,4,5,6}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST21
  printf("\"%s\"",s=toString(intersect(s1,s2)));;
  printf("\t\t<== \"{3,4}\"\t\t[intersect,toString]");
  if (strcmp(s,"{3,4}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST22
  printf("\"%s\"",s=toString(diff(s1,s2)));;
  printf("\t\t<== \"{1,2}\"\t\t[diff,toString]");
  if (strcmp(s,"{1,2}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST23
  printf("\"%s\"",s=toString(union_(createSet(),createSet())));
  printf("\t\t<== \"{}\"\t\t[toString,union]");
  if (strcmp(s,"{}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST24
  clear(s1); clear(s2);
  add(s2,100); add(s2,200);
  printf("\"%s\"",s=toString(diff(s1,s2)));
  printf("\t\t<== \"{}\"\t\t[add,diff,toString]");
  if (strcmp(s,"{}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST25
  printf("\"%s\"",s=toString(diff(s2,s2)));
  printf("\t\t<== \"{}\"\t\t[diff,toString]");
  if (strcmp(s,"{}")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  char str[100] = "";
  printf("%2d: ",++c);
#ifndef TEST26
  clear(s1);
  for (int i = 1; i <= 4; i++) add(s1,i);
  int *arr = toArray(s1);
  for (int i = 0; i < 4; i++) {
    strcat(str,tostring(arr[i]));
    strcat(str," ");
  }
  printf("%s",str);
  printf("\t\t<== 1 2 3 4 \t\t[toArray,toString]");
  if (strcmp(str,"1 2 3 4 ")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("%2d: ",++c);
#ifndef TEST27
  remove_(s1,2);
  printf("%s",str);
  printf("\t\t<== 1 2 3 4 \t\t[toArray,toString]");
  if (strcmp(str,"1 2 3 4 ")!=0) { printf("\t--incorrect--"); numWrong++; f[c] = true; }
#else
  numWrong++; f[c] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  printf("\nnumber of tests failed: %d\n",numWrong);
  if (numWrong>0) {
    printf("failed test(s): ");

    for (int i = 1; i <= 32; i++)
      if(f[i]) printf("%d ",i);
    printf("\n");
  }

  destroySet(s1);

}
