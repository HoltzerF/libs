#ifndef VMATH_H
#define VMATH_H

// -------------------
// COPYING
// -------------------

void cpy2f(float *v0, float *v1);
void cpy3f(float *v0, float *v1);
void cpy4f(float *v0, float *v1);
void cpynf(float *v0, float *v1, int n);

// ---------
// INVERT
// ---------

void inv2f(float *v);
void inv3f(float *v);
void inv4f(float *v);
void invnf(float *v, int n);

// -------------------
// ADDITION
// -------------------

void add2f(float *v0, float *v1, float *v2);
void add3f(float *v0, float *v1, float *v2);
void add4f(float *v0, float *v1, float *v2);
void addnf(float *v1, float *v2, float *v3, int n);

// ---------------
// SUBTRACTION
// --------------

void sub2f(float *v0, float *v1, float *v2);
void sub3f(float *v0, float *v1, float *v2);
void sub4f(float *v0, float *v1, float *v2);
void subnf(float *v0, float *v1, float *v2, int n);

// --------------
// MULTIPLICATION
// --------------

void mult2f(float *v0, float *v1, float *v2);
void mult3f(float *v0, float *v1, float *v2);
void mult4f(float *v0, float *v1, float *v2);
void multnf(float *v0, float *v1, float *v2, int n);

// -------------
// SCALING
// -------------

void scale2f(float *v, float s);
void scale3f(float *v, float s);
void scale4f(float *v, float s);
void scalenf(float *v, float s, int n);

// ----------------
// DOT PRODUCT
// ----------------

float dot2f(float *v0, float *v1);
float dot3f(float *v0, float *v1);
float dot4f(float *v0, float *v1);
float dotnf(float *v0, float *v1, int n);

// ---------------
// CROSS PRODUCT
// ---------------

void cross3f(float *v0, float *v1, float *v2);

// -------------
// LENGTH
// -------------

float len2f(float *v);
float len3f(float *v);
float len4f(float *v);
float lennf(float *v, int n);

// -------------
// NORMALIZE
// -------------

void normalize2f(float *v);
void normalize3f(float *v);
void normalize4f(float *v);
void normalizenf(float *v, int n);

// ---------------
// DISTANCE
// ---------------

float dist2f(float *v0, float *v1);
float dist3f(float *v0, float *v1);
float dist4f(float *v0, float *v1);
// TODO

// -----------------
// MATRIX STUFF
// -----------------

#endif // VMATH_H
