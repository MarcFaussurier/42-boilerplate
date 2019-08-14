#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c07.h"

int		main(void)
{
	testc07();
	MU_REPORT();
	return (minunit_fail);
}

