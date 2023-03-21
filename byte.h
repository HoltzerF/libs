#ifndef BYTE_H
#define BYTE_H

#define BIT_SET(byte, n)(byte |= (1 << n))
#define BIT_TEST(byte, n)(byte & (1 << n))
#define BIT_DEL(byte, n)(byte &= ~(1 << n))
#define BIT_TGL(byte, n)(byte ^= (1 << n))

void bitSet(char *byte, int n);
int bitTest(char *byte, int n);
void bitDel(char *byte, int n);
void bitTgl(char *byte, int n);
void printBin(char byte);
void printHex(char b);
void printBytesBin(void *bytes, int n);
void printBytesHex(void *bytes, int n);

#endif // BYTE_H
