#include "mypow.h"
#include <math.h>

float mypow(int x, int y){
	float pow = 1;
	if(x == 0 && y <= 0){
		return NAN;
	}else if(x > 0 &&y < 0){
		for(int i=0; i<abs(y); i++){
				pow = pow / x;
		}
		return pow;
	}else{
		int pow = 1;
		for(int i=0; i<y; i++){
				pow = pow * x;
		}
		return pow;
	}
}
