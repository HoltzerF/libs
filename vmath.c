#include "vmath.h"

// -------------------
// COPYING
// -------------------

void cpy2f(float *v0, float *v1){
	v1[0] = v0[0];
	v1[1] = v0[1];
}

void cpy3f(float *v0, float *v1){
	v1[0] = v0[0];
	v1[1] = v0[1];
	v1[2] = v0[2];
}

void cpy4f(float *v0, float *v1){
	v1[0] = v0[0];
	v1[1] = v0[1];
	v1[2] = v0[2];
	v1[3] = v0[3];
}

void cpynf(float *v0, float *v1, int n){
	int i;
	for(i = 0; i < n; ++i){
		v1[i] = v0[i];
	}
}

// ---------
// INVERT
// ---------

void inv2f(float *v){
	v[0] = -v[0];
	v[1] = -v[1];
}

void inv3f(float *v){
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

void inv4f(float *v){
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
	v[3] = -v[3];
}

void invnf(float *v, int n){
	while(--n >= 0){
		v[n] = -v[n];
	}
}

// -------------------
// ADDITION
// -------------------

void add2f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] + v1[0];
	v2[1] = v0[1] + v1[1];
}

void add3f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] + v1[0];
	v2[1] = v0[1] + v1[1];
	v2[2] = v0[2] + v1[2];
}

void add4f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] + v1[0];
	v2[1] = v0[1] + v1[1];
	v2[2] = v0[2] + v1[2];
	v2[3] = v0[3] + v1[3];
}

void addnf(float *v1, float *v2, float *v3, int n){
	while(--n >= 0){
		v3[n] = v1[n] + v2[n];
	}
}

// ---------------
// SUBTRACTION
// --------------

void sub2f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] - v1[0];
	v2[1] = v0[1] - v1[1];
}

void sub3f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] - v1[0];
	v2[1] = v0[1] - v1[1];
	v2[2] = v0[2] - v1[2];
}

void sub4f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] - v1[0];
	v2[1] = v0[1] - v1[1];
	v2[2] = v0[2] - v1[2];
	v2[3] = v0[3] - v1[3];
}

void subnf(float *v0, float *v1, float *v2, int n){
	while(--n >= 0){
		v2[n] = v0[n] - v1[n];
	}
}

// --------------
// MULTIPLICATION
// --------------

void mult2f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] * v1[0];
	v2[1] = v0[1] * v1[1];
}

void mult3f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] * v1[0];
	v2[1] = v0[1] * v1[1];
	v2[2] = v0[2] * v1[2];
}

void mult4f(float *v0, float *v1, float *v2){
	v2[0] = v0[0] * v1[0];
	v2[1] = v0[1] * v1[1];
	v2[2] = v0[2] * v1[2];
	v2[3] = v0[3] * v1[3];
}

void multnf(float *v0, float *v1, float *v2, int n){
	while(--n >= 0){
		v2[n] = v0[n] * v1[n];
	}
}

// -------------
// SCALING
// -------------

void scale2f(float *v, float s){
	v[0] *= s; v[1] *= s;
}

void scale3f(float *v, float s){
	v[0] *= s; v[1] *= s; v[2] *= s;
}

void scale4f(float *v, float s){
	v[0] *= s; v[1] *= s; v[2] *= s; v[3] *= s;
}

void scalenf(float *v, float s, int n){
	while(--n >= 0){
		v[n] *= s;
	}
}

// ----------------
// DOT PRODUCT
// ----------------

float dot2f(float *v0, float *v1){
	return v0[0] * v1[0] + v0[1] * v1[1];
}

float dot3f(float *v0, float *v1){
	return v0[0] * v1[0] + v0[1] * v1[1] + v0[2] * v1[2];
}

float dot4f(float *v0, float *v1){
	return v0[0] * v1[0] + v0[1] * v1[1] + v0[2] * v1[2] + v0[3] * v1[3];
}

float dotnf(float *v0, float *v1, int n){
	float sum = 0;
	while(--n >= 0){
		sum += v0[n] * v1[n];
	}
}

// ---------------
// CROSS PRODUCT
// ---------------

void cross3f(float *v0, float *v1, float *v2){
	v2[0] = v0[1] * v1[2] - v0[2] * v1[1];
	v2[1] = v0[2] * v1[0] - v0[0] * v1[2];
	v2[2] = v0[0] * v1[1] - v0[1] * v1[0];
}

// -------------
// LENGTH
// -------------

float len2f(float *v){
	return sqrtf(v[0] * v[0] + v[1] * v[1]);
}

float len3f(float *v){
	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

float len4f(float *v){
	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}

float lennf(float *v, int n){
	return 0;
}

// -------------
// NORMALIZE
// -------------

void normalize2f(float *v){
	float l = len2f(v);
	if(l == 0) return;
	l = 1 / l;
	scale2f(v, l);
}

void normalize3f(float *v){
	float l = len3f(v);
	if(l == 0) return;
	l = 1 / l;
	scale3f(v, l);
}

void normalize4f(float *v){
	float l = len4f(v);
	if(l == 0) return;
	l = 1 / l;
	scale4f(v, l);
}

void normalizenf(float *v, int n){
	float l = lennf(v, n);
	if(l == 0) return;
	l = 1 / l;
	scalenf(v, l, n);
}

// ---------------
// DISTANCE
// ---------------

float absf(float n){
	if(n < 0){
		return -n;
	}
	return n;
}

float dist2f(float *v0, float *v1){
	float v[2];
	sub2f(v1, v0, v);
	return absf(len2f(v));
}

float dist3f(float *v0, float *v1){
	float v[3];
	sub3f(v1, v0, v);
	return absf(len3f(v));
}

float dist4f(float *v0, float *v1){
	float v[4];
	sub4f(v1, v0, v);
	return absf(len4f(v));
}

// TODO

// -----------------
// MATRIX STUFF
// -----------------

void mat2_set(float *m, float m00, float m01, float m10, float m11){
	m[0] = m00; m[1] = m01; m[2] = m10; m[3] = m11;
}

void mat2_mult(float *m0, float *m1, float *m2){
	
}

/* we are using column-major matrices
 */

void _setMatrixElem(float m[16], int elem, float val){ // elem[1, 16]
	m[elem - 1] = val;
}

float _getMatrixElem(float m[16], int elem){ // elem[1, 16]
	return m[elem - 1];
}

void _setMatrixRC(float m[16], int row, int col, float val){ // row[1,4], column[1,4]
	m[(col - 1) * 4 + (row - 1)] = val;
}

float _getMatrixRC(float m[16], int row, int col){ // row[1,4], column[1,4]
	return m[(col - 1) * 4 + (row - 1)];
}

void transposeMatrix(float m0[16], float m1[16]){
	int i, j;
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			m1[i + j * 4] = m0[j + i * 4];
		}
	}
}

void _vertexMultiplyMatrix(float m[16], float in[4], float out[4]){
	out[0] = in[0] * m[0] + in[1] * m[4] + in[2] * m[8] + in[3] * m[12];
	out[1] = in[0] * m[1] + in[1] * m[5] + in[2] * m[9] + in[3] * m[13];
	out[2] = in[0] * m[2] + in[1] * m[6] + in[2] * m[10] + in[3] * m[14];
	out[3] = in[0] * m[3] + in[1] * m[7] + in[2] * m[11] + in[3] * m[15];
}

void _vertexMultiplyMatrixUpperLeft(float m[16], float in[3], float out[3]){
	out[0] = in[0] * m[0] + in[1] * m[4] + in[2] * m[8];
	out[1] = in[0] * m[1] + in[1] * m[5] + in[2] * m[9];
	out[2] = in[0] * m[2] + in[1] * m[6] + in[2] * m[10];
}

void _transposeVertexMultiplyMatrix(float in[4], float out[4], float m[16]){
	out[0] = in[0] * m[0] + in[0] * m[4] + in[0] * m[8] + in[0] * m[12];
	out[1] = in[1] * m[1] + in[1] * m[5] + in[1] * m[9] + in[1] * m[13];
	out[2] = in[2] * m[2] + in[2] * m[6] + in[2] * m[10] + in[2] * m[14];
	out[3] = in[3] * m[3] + in[3] * m[7] + in[3] * m[11] + in[3] * m[15];
}

int gluInvertMatrix(float m[16], float invOut[16]) {
	float inv[16], det;
	int i;

	inv[0] = m[5] * m[10] * m[15] -
		m[5] * m[11] * m[14] -
		m[9] * m[6] * m[15] +
		m[9] * m[7] * m[14] +
		m[13] * m[6] * m[11] -
		m[13] * m[7] * m[10];

	inv[4] = -m[4] * m[10] * m[15] +
		m[4] * m[11] * m[14] +
		m[8] * m[6] * m[15] -
		m[8] * m[7] * m[14] -
		m[12] * m[6] * m[11] +
		m[12] * m[7] * m[10];

	inv[8] = m[4] * m[9] * m[15] -
		m[4] * m[11] * m[13] -
		m[8] * m[5] * m[15] +
		m[8] * m[7] * m[13] +
		m[12] * m[5] * m[11] -
		m[12] * m[7] * m[9];

	inv[12] = -m[4] * m[9] * m[14] +
		m[4] * m[10] * m[13] +
		m[8] * m[5] * m[14] -
		m[8] * m[6] * m[13] -
		m[12] * m[5] * m[10] +
		m[12] * m[6] * m[9];

	inv[1] = -m[1] * m[10] * m[15] +
		m[1] * m[11] * m[14] +
		m[9] * m[2] * m[15] -
		m[9] * m[3] * m[14] -
		m[13] * m[2] * m[11] +
		m[13] * m[3] * m[10];

	inv[5] = m[0] * m[10] * m[15] -
		m[0] * m[11] * m[14] -
		m[8] * m[2] * m[15] +
		m[8] * m[3] * m[14] +
		m[12] * m[2] * m[11] -
		m[12] * m[3] * m[10];

	inv[9] = -m[0] * m[9] * m[15] +
		m[0] * m[11] * m[13] +
		m[8] * m[1] * m[15] -
		m[8] * m[3] * m[13] -
		m[12] * m[1] * m[11] +
		m[12] * m[3] * m[9];

	inv[13] = m[0] * m[9] * m[14] -
		m[0] * m[10] * m[13] -
		m[8] * m[1] * m[14] +
		m[8] * m[2] * m[13] +
		m[12] * m[1] * m[10] -
		m[12] * m[2] * m[9];

	inv[2] = m[1] * m[6] * m[15] -
		m[1] * m[7] * m[14] -
		m[5] * m[2] * m[15] +
		m[5] * m[3] * m[14] +
		m[13] * m[2] * m[7] -
		m[13] * m[3] * m[6];

	inv[6] = -m[0] * m[6] * m[15] +
		m[0] * m[7] * m[14] +
		m[4] * m[2] * m[15] -
		m[4] * m[3] * m[14] -
		m[12] * m[2] * m[7] +
		m[12] * m[3] * m[6];

	inv[10] = m[0] * m[5] * m[15] -
		m[0] * m[7] * m[13] -
		m[4] * m[1] * m[15] +
		m[4] * m[3] * m[13] +
		m[12] * m[1] * m[7] -
		m[12] * m[3] * m[5];

	inv[14] = -m[0] * m[5] * m[14] +
		m[0] * m[6] * m[13] +
		m[4] * m[1] * m[14] -
		m[4] * m[2] * m[13] -
		m[12] * m[1] * m[6] +
		m[12] * m[2] * m[5];

	inv[3] = -m[1] * m[6] * m[11] +
		m[1] * m[7] * m[10] +
		m[5] * m[2] * m[11] -
		m[5] * m[3] * m[10] -
		m[9] * m[2] * m[7] +
		m[9] * m[3] * m[6];

	inv[7] = m[0] * m[6] * m[11] -
		m[0] * m[7] * m[10] -
		m[4] * m[2] * m[11] +
		m[4] * m[3] * m[10] +
		m[8] * m[2] * m[7] -
		m[8] * m[3] * m[6];

	inv[11] = -m[0] * m[5] * m[11] +
		m[0] * m[7] * m[9] +
		m[4] * m[1] * m[11] -
		m[4] * m[3] * m[9] -
		m[8] * m[1] * m[7] +
		m[8] * m[3] * m[5];

	inv[15] = m[0] * m[5] * m[10] -
		m[0] * m[6] * m[9] -
		m[4] * m[1] * m[10] +
		m[4] * m[2] * m[9] +
		m[8] * m[1] * m[6] -
		m[8] * m[2] * m[5];

	det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

	if(det == 0){
		return 1;
	}

	det = 1.0 / det;

	for(i = 0; i < 16; i++){
		invOut[i] = inv[i] * det;
	}

	return 0;
}

void _inverseMatrix(float in[16], float out[16]){
	gluInvertMatrix(in, out);
}
