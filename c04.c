#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c04.h"

int		main(void)
{
	testc04();
	MU_REPORT();
	return (minunit_fail);
}

