#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c10.h"

int		main(void)
{
	testc10();
	MU_REPORT();
	return (minunit_fail);
}

