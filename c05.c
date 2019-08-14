#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c05.h"

int		main(void)
{
	testc05();
	MU_REPORT();
	return (minunit_fail);
}

