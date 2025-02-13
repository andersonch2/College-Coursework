/* to compile:
     gcc labrat.c ratprojGrader.c
   to compile and remove TEST3, TEST4:
     gcc labrat ratprojGrader.c -DTEST3 -DTEST4
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "labrat.h"

// defining the following removes the routines
// you are not implementing for the lab
#define TEST8
#define TEST9
#define TEST10
#define TEST11
#define TEST12
#define TEST13
#define TEST14
#define TEST15
#define TEST16
#define TEST17
#define TEST18
#define TEST19
#define TEST20
#define TEST21
#define TEST22
#define TEST23
#define TEST24
#define TEST25



int main(void) {
  rat r;  
  rat r1 = createRat(2,3), r2 = createRat(2,-3), r3 = createRat(72,-294),
    r4 = createRat(0,-76), r5 = createRat(77,-77), r6 = createRat(-0,300),
    r7 = createRat(-3,-5), r8 = createRat(121,2), r9 = createRat(200,300),
    r10 = createRat(2,3), r11 = createRat(-6,7);
  
  int n,d, numWrong=0;
  int c=0;
  bool f[33] = { 0 };
  
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST1
  printf("%d,%d",n=getNum(r1),d=getDenom(r1));
  printf("\t\t<== 2,3\t\t[createRat]");
  if (n!=2 || d!=3) { printf("\t--incorrect--"); numWrong++; f[1] = true; }
#else
  numWrong++; f[1] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST2
  printf("%d,%d",n=getNum(r2),d=getDenom(r2));
  printf("\t<== 2,-3\t[createRat]");
  if (n!=2 || d!=-3) { printf("\t--incorrect--"); numWrong++; f[2] = true; }
#else
  numWrong++; f[2] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");
	       
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST3
  printf("%d,%d",n=getNum(r4),d=getDenom(r4));
  printf("\t<== 0,-76\t[createRat]");
  if (n!=0 || d!=-76) { printf("\t--incorrect--"); numWrong++; f[3] = true; }
#else
  numWrong++; f[3] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST4
  r=norm(r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 2,3\t\t[norm]");
  if (n!=2 || d!=3) { printf("\t--incorrect--"); numWrong++; f[4] = true; }
#else
  numWrong++; f[4] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST5
  r=norm(r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t<== -2,3\t[norm]");
  if (n!=-2 || d!=3) { printf("\t--incorrect--"); numWrong++; f[5] = true; }
#else
  numWrong++; f[5] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");
  
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST6
  r=norm(r6);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[norm]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[6] = true; }
#else
  numWrong++; f[6] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");
  
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST7
  r=norm(r7);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 3,5\t\t[norm]");
  if (n!=3 || d!=5) { printf("\t--incorrect--"); numWrong++; f[7] = true; }
#else
  numWrong++; f[7] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");
  
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST8
  r=reduce(r3);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t<== 12,-49\t[reduce]");
  if (n!=12 || d!=-49) { printf("\t--incorrect--"); numWrong++; f[8] = true; }
#else
  numWrong++; f[8] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST9
  r=reduce(r4);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[reduce]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[9] = true; }
#else
  numWrong++; f[9] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST10
  r=reduce(r5);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t<== 1,-1\t[reduce]");
  if (n!=1 || d!=-1) { printf("\t--incorrect--"); numWrong++; f[10] = true; }
#else
  numWrong++; f[10] = true;
  printf("(test was removed from compilation.)");
  
#endif
  printf("\n");

  int x;
///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST11
  x = cmp(r1,r10);
  printf("%d",x);
  printf("\t\t<== 0\t\t[cmp]");
  if (x!=0) { printf("\t--incorrect--"); numWrong++; f[11] = true; }
#else
  numWrong++; f[11] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST12
  x = cmp(r9,r1);
  printf("%d",x);
  printf("\t\t<== 0\t\t[cmp]");
  if (x!=0) { printf("\t--incorrect--"); numWrong++; f[12] = true; }
#else
  numWrong++; f[12] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST13
  x = cmp(createRat(200,-300),r7);
  printf("%d",x);
  printf("\t\t<== -1\t\t[cmp]");
  if (x!=-1) { printf("\t--incorrect--"); numWrong++; f[13] = true; }
#else
  numWrong++; f[13] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST14
  x = cmp(r8,createRat(16,3));
  printf("%d",x);
  printf("\t\t<== 1\t\t[cmp]");
  if (x!=1) { printf("\t--incorrect--"); numWrong++; f[14] = true; }
#else
  numWrong++; f[14] = true;
  printf("(test was removed from compilation.)");
  
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST15
  r = add(r1,r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 4,3\t\t[add]");
  if (n!=4 || d!=3) { printf("\t--incorrect--"); numWrong++; f[15] = true; }
#else
  numWrong++; f[15] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST16
  r = add(r1,r9);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 4,3\t\t[add]");
  if (n!=4 || d!=3) { printf("\t--incorrect--"); numWrong++; f[16] = true; }
#else
  numWrong++; f[16] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST17
  r = add(r1,r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[add]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[17] = true; }
#else
  numWrong++; f[17] = true;
  printf("(test was removed from compilation.)");
  
#endif
  printf("\n");

  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST18
  r = sub(r2,r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[sub]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[18] = true; }
#else
  numWrong++; f[18] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST19
  r = sub(r6,r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 2,3\t\t[sub]");
  if (n!=2 || d!=3) { printf("\t--incorrect--"); numWrong++; f[19] = true; }
#else
  numWrong++; f[19] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST20
  r = mul(r1,r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 4,9\t\t[mul]");
  if (n!=4 || d!=9) { printf("\t--incorrect--"); numWrong++; f[20] = true; }
#else
  numWrong++; f[20] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST21
  r = mul(r1,r6);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[mul]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[21] = true; }
#else
  numWrong++; f[21] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST22
  r = mul(r5,r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 2,3\t\t[mul]");
  if (n!=2 || d!=3) { printf("\t--incorrect--"); numWrong++; f[22] = true; }
#else
  numWrong++; f[22] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST23
  r = divide(r1,r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 1,1\t\t[divide]");
  if (n!=1 || d!=1) { printf("\t--incorrect--"); numWrong++; f[23] = true; }
#else
  numWrong++; f[23] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST24
  r = divide(r7,r2);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t<== -9,10\t[divide]");
  if (n!=-9 || d!=10) { printf("\t--incorrect--"); numWrong++; f[24] = true; }
#else
  numWrong++; f[24] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST25
  r = divide(r6,r8);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 0,1\t\t[divide]");
  if (n!=0 || d!=1) { printf("\t--incorrect--"); numWrong++; f[25] = true; }
#else
  numWrong++; f[25] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST26
  r = inverse(r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 3,2\t\t[inverse]");
  if (n!=3 || d!=2) { printf("\t--incorrect--"); numWrong++; f[26] = true; }
#else
  numWrong++; f[26] = true;
  printf("(test was removed from compilation.)");
  
#endif
  printf("\n");
  
  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST27
  r = inverse(r1);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t\t<== 3,2\t\t[inverse]");
  if (n!=3 || d!=2) { printf("\t--incorrect--"); numWrong++; f[27] = true; }
#else
  numWrong++; f[27] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");
  
  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST28
  r = inverse(r11);
  printf("%d,%d",n=getNum(r),d=getDenom(r));
  printf("\t<== 7,-6\t[inverse]");
  if (n!=7 || d!=-6) { printf("\t--incorrect--"); numWrong++; f[28] = true; }
#else
  numWrong++; f[28] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

  char *s;
  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST29
  s = toString(r1);
  printf("\"%s\"",s);
  printf("\t<==\"2,3\"\t[toString]");
  if (!(strcmp(s,"2/3")==0)) { printf("\t--incorrect--"); numWrong++; f[29] = true; }
#else
  numWrong++; f[29] = true;
  printf("(test was removed from compilation.)");
  
#endif
  printf("\n");

  
  ///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST30
  s = toString(r11);
  printf("\"%s\"",s);
  printf("\t<==\"-6/7\"\t[toString]");
  if (!(strcmp(s,"-6/7")==0)) { printf("\t--incorrect--"); numWrong++; f[30] = true; }
#else
  numWrong++; f[30] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST31
  x = wellFormed(r1);
  printf("%d",x);
  printf("\t\t<== 1\t\t[wellFormed]");
  if (x!=1) { printf("\t--incorrect--"); numWrong++; f[32] = true; }
#else
  numWrong++; f[31] = true;
  printf("(test was removed from compilation.)");
#endif
  printf("\n");

///////////////////////////////////////////
  printf("%2d: ",++c);
#ifndef TEST32
  setDenom(r1,0);
  x = wellFormed(r1);
  printf("%d",x);
  printf("\t\t<== 0\t\t[wellFormed]");
  if (x!=0) { printf("\t--incorrect--"); numWrong++; f[32] = true; }
#else
  numWrong++; f[32] = true;
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
}

