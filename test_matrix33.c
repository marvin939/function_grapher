#include "test_matrix33.h"
#include "matrix33.h"
#include <stdio.h>

static void test_matrix33_get();
static void test_matrix33_set();
static void test_matrix33_vmul();
static void test_matrix33_smul();
static void test_matrix33_mmul();

void test_matrix33_runAll()
{
	printf("Running all matrix33 tests...\n");

	test_matrix33_get();
	test_matrix33_set();
	test_matrix33_vmul();
	test_matrix33_smul();
	test_matrix33_mmul();

	printf("Success\n");
}

static void test_matrix33_get()
{
	M33 m = {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
	assert(matrix33_get(&m, 3, 3) == 9 && "matrix33_get failed");
	assert(matrix33_get(&m, 3, 2) == 8 && "matrix33_get failed");
	assert(matrix33_get(&m, 1, 1) == 1 && "matrix33_get failed");
}

static void test_matrix33_set()
{
	M33 m = {{}};
	matrix33_set(&m, 1, 1, 1);
	matrix33_set(&m, 1, 2, 2);
	matrix33_set(&m, 1, 3, 3);
	matrix33_set(&m, 2, 1, 4);
	matrix33_set(&m, 2, 2, 5);
	matrix33_set(&m, 2, 3, 6);
	matrix33_set(&m, 3, 1, 7);
	matrix33_set(&m, 3, 2, 8);
	matrix33_set(&m, 3, 3, 9);

	assert(matrix33_get(&m, 1, 1) == 1 && "matrix33_set failed");
	assert(matrix33_get(&m, 1, 2) == 2 && "matrix33_set failed");
	assert(matrix33_get(&m, 1, 3) == 3 && "matrix33_set failed");
	assert(matrix33_get(&m, 2, 1) == 4 && "matrix33_set failed");
	assert(matrix33_get(&m, 2, 2) == 5 && "matrix33_set failed");
	assert(matrix33_get(&m, 2, 3) == 6 && "matrix33_set failed");
	assert(matrix33_get(&m, 3, 1) == 7 && "matrix33_set failed");
	assert(matrix33_get(&m, 3, 2) == 8 && "matrix33_set failed");
	assert(matrix33_get(&m, 3, 3) == 9 && "matrix33_set failed");
}

static void test_matrix33_vmul()
{
	M33 m = {{1, 0, 0,
	          0, 2, 0,
			  0, 0, 3}};
	vec3 v = {1, 2, 3};
	vec3 res = matrix33_vmul(&m, &v);

	assert(res.x == 1 && "matrix33_vmul #1 fail");
	assert(res.y == 4 && "matrix33_vmul #1 fail");
	assert(res.z == 9 && "matrix33_vmul #1 fail");

	M33 m2 = {{1, 0, 40,
	           0, 1, 45,
		       0, 0, 1}};
	res = matrix33_vmul(&m2, &v);	// transpose by 3*(40,45) b.c. v's z=3.
	assert(res.x == 121 && "matrix33_vmul #2 fail");
	assert(res.y == 137 && "matrix33_vmul #2 fail");
	assert(res.z == 3 && "matrix33_vmul #2 fail");
}

static void test_matrix33_smul()
{
	M33 m = {{1, 0, 2,
	          0, 2, 0,
			  0, 0, 3}};
	real s = 50;
	M33 res = matrix33_smul(s, &m);
	assert(matrix33_get(&res, 1, 1) == 50);
	assert(matrix33_get(&res, 1, 3) == 100);
	assert(matrix33_get(&res, 2, 2) == 100);
	assert(matrix33_get(&res, 3, 3) == 150);
	assert(matrix33_get(&res, 3, 2) == 0);
}

static void test_matrix33_mmul()
{
	M33 A = {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
	M33 B = {{10, 11, 12, 13, 14, 15, 16, 17, 18}};
	M33 C = matrix33_mmul(&A, &B);
	//      84    90    96
	// C = 201   216   231
	//	   318   342   366

	assert(matrix33_get(&C, 1, 1) == 84);
	assert(matrix33_get(&C, 1, 2) == 90);
	assert(matrix33_get(&C, 1, 3) == 96);
	assert(matrix33_get(&C, 2, 1) == 201);
	assert(matrix33_get(&C, 2, 2) == 216);
	assert(matrix33_get(&C, 2, 3) == 231);
	assert(matrix33_get(&C, 3, 1) == 318);
	assert(matrix33_get(&C, 3, 2) == 342);
	assert(matrix33_get(&C, 3, 3) == 366);

	B = matrix33_smul(-1, &B);
	C = matrix33_mmul(&A, &B);
	assert(matrix33_get(&C, 1, 1) == -84);
	assert(matrix33_get(&C, 1, 2) == -90);
	assert(matrix33_get(&C, 1, 3) == -96);
	assert(matrix33_get(&C, 2, 1) == -201);
	assert(matrix33_get(&C, 2, 2) == -216);
	assert(matrix33_get(&C, 2, 3) == -231);
	assert(matrix33_get(&C, 3, 1) == -318);
	assert(matrix33_get(&C, 3, 2) == -342);
	assert(matrix33_get(&C, 3, 3) == -366);
}
