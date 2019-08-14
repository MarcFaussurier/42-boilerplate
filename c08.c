#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c08.h"

int		main(void)
{
	testc08();
	MU_REPORT();
	return (minunit_fail);
}

