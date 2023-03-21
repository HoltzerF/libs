#ifndef USEFUL_H
#define USEFUL_H

// some min and max macros
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#define min3(a, b, c) (a < b ? min(a, c) : min(b, c))
#define max3(a, b, c) (a < b ? max(b, c) : max(a, c))

int clampRangei(int i, int min, int max);
float clampRangef(float f, float min, float max);
float clampf(float f);

// delays functions by some milliseconds
void delay(int millis);

// getting the absolute value of an float
float absf(float n);

// getting the absolute value of an integer
int absi(int n);

// returns the greates common divisor of two positive numbers
int gcdPos(int a, int b);

// returns the greatest common divisor
int gcd(int a, int b);

// reverses an byte array
void bytesRev(void *mem, int len);

// swapping two memory areas
void swapMem(void *a, void *b, int size);

// calculates the factorial, mind integer overflow
int factorial(int n);

// checks if a number is prime
int isPrime(int n);

// maps a range and a specific value in that range to another range, inclusive
float range(float value, float min, float max, float mmin, float mmax);

// maps random values to a given range
float mrand(float min, float max);

// returns the fibonacci number for a specific position
// if h is smaller than zero, function returns -1
int fibonacci(int h);

// same as n % 2
int mod2(int n);

// same as n % m
int mod(int n, int m);

// linear interpolates values by an amount t
float learp(float a, float b, float t);

#endif // USEFUL_H
