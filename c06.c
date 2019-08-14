#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c06.h"

int		main(void)
{
	testc06();
	MU_REPORT();
	return (minunit_fail);
}

