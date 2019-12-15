#include "matrix33.h"

real matrix33_get(matrix33 const * const m33, int const row, int const col)
{
	return m33->coef[(row - 1) * 3 - 1 + col];
}

real matrix33_set(matrix33 * const m33, int const row, int const col, real const val)
{
	m33->coef[(row - 1) * 3 - 1 + col] = val;
	return val;
}

vec3 matrix33_vmul(matrix33 const * const m33, vec3 const * const vec)
{
	real const * const cf = m33->coef;
	
	return (vec3){
		cf[0] * vec->x + cf[1] * vec->y + cf[2] * vec->z,
		cf[3] * vec->x + cf[4] * vec->y + cf[5] * vec->z,
		cf[6] * vec->x + cf[7] * vec->y + cf[8] * vec->z,
	};
}

M33 matrix33_smul(real const scalar, matrix33 const * const m33)
{
	matrix33 ret;
	int i;
	for (i = 0; i < 9; ++i) {
		ret.coef[i] = m33->coef[i] * scalar;
	}
	
	return ret;
}

M33 matrix33_mmul(M33 const * const ma, M33 const * const mb)
{
	real const * const a = ma->coef;
	real const * const b = mb->coef;
	
	return (M33) {{
		(a[0]*b[0] + a[1]*b[3] + a[2]*b[6]), (a[0]*b[1] + a[1]*b[4] + a[2]*b[7]), (a[0]*b[2] + a[1]*b[5] + a[2]*b[8]),
		(a[3]*b[0] + a[4]*b[3] + a[5]*b[6]), (a[3]*b[1] + a[4]*b[4] + a[5]*b[7]), (a[3]*b[2] + a[4]*b[5] + a[5]*b[8]),
		(a[6]*b[0] + a[7]*b[3] + a[8]*b[6]), (a[6]*b[1] + a[7]*b[4] + a[8]*b[7]), (a[6]*b[2] + a[7]*b[5] + a[8]*b[8])
	}};
}
