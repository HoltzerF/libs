#include "useful.h"

void delay(int millis){
	clock_t start = clock();
	while(( (float)(clock() - start) / CLOCKS_PER_SEC * 1000) <= millis)
		;
}

int absolute(int n){
	if(n < 0)
		return -n;
	return n;
}

int gcdPos(int a, int b){
	while(a != b){
		if(a > b){
			a -= b;
		}else{
			b -= a;
		}
	}
	return a;
}

int gcd(int a, int b){
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	
	while(a != b){
		if(a > b){
			a -= b;
		}else{
			b -= a;
		}
	}
	return a;
}

void bytesRev(void *mem, int len){
	char *beg = (char *)mem;
	char *end = beg + len - 1;
	
	while(beg < end){
		char temp = *end;
		*end-- = *beg;
		*beg++ = temp;
	}
}

void swapMem(void *a, void *b, int size){
	char *p_a = (char *)a;
	char *p_b = (char *)b;
	
	do{
		char temp = *p_a;
		*p_a++ = *p_b;
		*p_b++ = temp;
	}while(--size > 0);
}

int factorial(int n){
	int i, faco;
	for(i = 1, faco = 1; i <= n; i++)
  		faco *= i;
	return faco;
}

int isPrime(int n){
	int i;
	for(i = 2; i <= n / 2; ++i){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

float range(float value, float min, float max, float mmin, float mmax){
	return (mmax - mmin) * ((value - min) / (max - min)) + mmin;
}

float mrand(float min, float max){
	return range(rand(), 0, RAND_MAX, min, max);
}

int fibonacci(int h){
	int l, n, f;	// last, new, fibo
	f = l = -1;
	n = 1;
	
	while(h-- > -1){
		f = l + n;
		l = n;
		n = f;
	}
	
	return f;
}

int mod2(int n){
	return (n & 1) * (1 - 2 * (n < 0));
}

int mod(int n, int m){
    return (n - m * (n / m));
}

float lerp(float a, float b, float t){
	return a * (1 - t) + t * b;
}
