#ifndef BYTE_H
#define BYTE_H

#include <stdio.h>

int bitTest(char byte, int n);
void bitSet(char *byte, int n);
void bitDel(char *byte, int n);
void bitTgl(char *byte, int n);
void printByte(char byte);
void printBytes(void *bytes, int n);

#endif
