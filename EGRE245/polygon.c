#include <stdio.h>

typedef struct{
  int height;
  int width;
}Polygon_t;

int main(void){
  Polygon_t* poly = NULL;
  //Creating the dynamic memory
  poly = (Polygon_t*)malloc(1*sizeof(Polygon_t));
  printf("Enter the height of the polygon: \n");
  scanf("%d", &poly->height);
  printf("Enter the width of the polygon: \n");
  scanf("%d", &poly->width);
  int area = poly.height * poly.width;
  printf("%d", area);
  //Removing the dynamic memory
  free(poly);
  return 0;
}
