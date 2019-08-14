#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c13.h"

int		main(void)
{
	testc13();
	MU_REPORT();
	return (minunit_fail);
}

