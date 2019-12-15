#ifndef MATRIX33_H
#define MATRIX33_H

#include "vec3.h"

typedef struct {
	real coef[9];
} matrix33;

typedef matrix33 M33;

// Get/Set matrix coefficient @ row,column
real matrix33_get(matrix33 const * const m33, int const row, int const col);
real matrix33_set(matrix33 * const m33, int const row, int const col, real const val);

// Transform a vector with a matrix.
vec3 matrix33_vmul(matrix33 const * const m33, vec3 const * const vec);

// Scalar multiply a matrix.
M33 matrix33_smul(real const scalar, matrix33 const * const m33);

// Multiply two matrices (left to right)
M33 matrix33_mmul(M33 const * const ma, M33 const * const mb);

#endif
