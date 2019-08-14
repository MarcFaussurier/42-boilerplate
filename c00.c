#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c00.h"

int		main(void)
{
	testc00();
	MU_REPORT();
	return (minunit_fail);
}

