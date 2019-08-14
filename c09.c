#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c09.h"

int		main(void)
{
	testc09();
	MU_REPORT();
	return (minunit_fail);
}

