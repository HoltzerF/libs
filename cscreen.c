#include "cscreen.h"

void cbClear(char c){
	c *= !(c < 32 || c > 126);
	int i;
	for(i = 0; i < WIDTH * HEIGHT - 1; ++i){
		cbScreen[i] = c;
	}
}

void cbFlush(){
	printf(" %s", cbScreen);
}

void cbInit(){
	cbClear(' ');
	cbScreen[WIDTH * HEIGHT - 1] = '\0';
	printf("%s", cbScreen);
}

void cbPixel(int x, int y, char c){
	if(x >= 0 && y >= 0 && c >= 32 && c < 126){
		int pos = y * WIDTH + x;
		if(pos < WIDTH * HEIGHT - 1){
			cbScreen[pos] = c;
		}
	}
}

void cbString(int x, int y, char *s){
	while(*s){
		cbPixel(x++, y, *s++);
	}
}
