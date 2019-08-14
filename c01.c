#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c01.h"

int		main(void)
{
	testc01();
	MU_REPORT();
	return (minunit_fail);
}

