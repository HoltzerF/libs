#include "byte.h"
#include <stdio.h>

void bitSet(char *byte, int n){
	*byte |= (1 << n);
}

int bitTest(char *byte, int n){
	return *byte & (1 << n);
}

void bitDel(char *byte, int n){
	*byte &= ~(1 << n);
}

void bitTgl(char *byte, int n){
	*byte ^= (1 << n);
}

void printBin(char byte){
	int i = 7;
	while(i >= 0){
		printf("%c ", '0' + (BIT_TEST(byte, i--) > 0));
	}
}

void printHex(char b){
	printf("0x%02x", b);
}

void printBytesBin(void *bytes, int n){
	char *ptr = bytes;
	int i;
	for(i = 0; i < n; ++i){
		printBin(ptr[i]);
		putchar(' ');
	}
}

void printBytesHex(void *bytes, int n){
	char *ptr = bytes;
	int i;
	for(i = 0; i < n; ++i){
		printHex(ptr[i]);
		putchar(' ');
	}
}
