#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c12.h"

int		main(void)
{
	testc12();
	MU_REPORT();
	return (minunit_fail);
}

