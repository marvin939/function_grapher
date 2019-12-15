#include "vec3.h"

vec3 vec3_add(vec3 const * const v1, vec3 const * const v2)
{
    return (vec3) {
        v1->x + v2->x,
        v1->y + v2->y,
        v1->z + v2->z
    };
}

vec3 vec3_sub(vec3 const * const v1, vec3 const * const v2)
{
    return (vec3) {
        v1->x - v2->x,
        v1->y - v2->y,
        v1->z - v2->z
    };
}

vec3 vec3_multiply(real const scalar, vec3 const * const vec)
{
	return (vec3) {
		vec->x * scalar,
		vec->y * scalar,
		vec->z * scalar
	};
}
