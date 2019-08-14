#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c11.h"

int		main(void)
{
	testc11();
	MU_REPORT();
	return (minunit_fail);
}

