#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

// Immutable vector only with respect to functions...

typedef double real;

typedef struct {
    real x, y, z;
} vec3;

vec3 vec3_add(vec3 const * const v1, vec3 const * const v2);
vec3 vec3_sub(vec3 const * const v1, vec3 const * const v2);
vec3 vec3_multiply(real const scalar, vec3 const * const vec);

#endif // VEC3_H_INCLUDED
