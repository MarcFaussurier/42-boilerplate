#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c03.h"

int		main(void)
{
	testc03();
	MU_REPORT();
	return (minunit_fail);
}

