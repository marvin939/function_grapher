#include <stdio.h>
#include <stdlib.h>
#include "test_vec3.h"
#include "test_matrix33.h"
#include "start.h"

void RUN_TESTS();

int main(int argc, char *argv[]) {
	RUN_TESTS();

	int r = start_runStuff(argc, argv);

    return r;
}
//END_OF_MAIN();


void RUN_TESTS()
{
	test_vec3_runAll();
	test_matrix33_runAll();
}
