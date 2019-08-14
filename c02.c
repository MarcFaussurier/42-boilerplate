#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c02.h"

int		main(void)
{
	testc02();
	MU_REPORT();
	return (minunit_fail);
}

