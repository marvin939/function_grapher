#include <assert.h>
#include <stdio.h>
#include "vec3.h"
#include "test_vec3.h"

static void test_vec3_sub();
static void test_vec3_add();
static void test_vec3_multiply();

void test_vec3_runAll()
{
	printf("Running all %s tests...\n", __FILE__);

    test_vec3_add();
    test_vec3_sub();
    test_vec3_multiply();

    printf("Success.\n");
}


void test_vec3_add()
{
	vec3 v1 = {1, 2, 3}, v2 = {4, 5, 6};
	vec3 v3 = vec3_add(&v1, &v2);
	assert(v3.x == 5 && "vec_add x incorrect");
	assert(v3.y == 7 && "vec_add y incorrect");
	assert(v3.z == 9 && "vec_add z incorrect");
}

static void test_vec3_sub()
{
	vec3 v1 = {4, 5, 6}, v2 = {1, 2, 3};
	vec3 v3 = vec3_sub(&v1, &v2);
	assert(v3.x == 3 && "vec_sub x incorrect");
	assert(v3.y == 3 && "vec_sub y incorrect");
	assert(v3.z == 3 && "vec_sub z incorrect");
}

void test_vec3_multiply()
{
	vec3 vec = {1, 2, 3};
	real scalar = 1./2;

	vec3 res = vec3_multiply(scalar, &vec);

	assert(res.x == 1/2. && "vec_multiply x incorrect");
	assert(res.y == 1.0 && "vec_multiply y incorrect");
	assert(res.z == 3/2. && "vec_multiply z incorrect");
}
