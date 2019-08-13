#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/minunit/minunit.h"
#include "tests/c00.h"
#include "tests/c01.h"
#include "tests/c02.h"
#include "tests/c03.h"
#include "tests/c04.h"
#include "tests/c05.h"
#include "tests/c06.h"
#include "tests/c07.h"
#include "tests/c08.h"
#include "tests/c09.h"
#include "tests/c10.h"
#include "tests/c11.h"
#include "tests/c12.h"
#include "tests/c13.h"

int		main(int argc, char**argv)
{
	int		should_stop;
	int		i;	
	int		days[99];
	int		innb;
	int		nb_days = 1;
	int		available_days[] = {0};

	should_stop = 0;
	if (argc == 1)
	{
		innb = 0;
		while (innb < nb_days)
		{
			innb = 0;
			printf("Press x to quit\n");
			while (!should_stop)
			{
				printf("Please enter the day you wish to test: \n");
				char buffer[3];
				read(STDIN_FILENO, buffer, 2);
				if (buffer[0] == 'x')
					break ;
				buffer[2] = '\0';
				days[innb] = atoi(buffer);
				innb += 1;
			}

		}
	}
	else if (argc == 2 && strcmp(argv[1], "all") == 0)
	{
		printf("testing everything...\n");
		innb = 0;
		while (innb < nb_days)
		{
			days[innb] = available_days[innb];
			innb += 1;
		}
	
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			days[i - 1] = atoi(argv[i]);
			i += 1;
		}
		innb = i - 2;
	}
	i = 0;
	while (i < innb)
	{
		switch (days[i])
		{
			case (0) :
				printf("You requested day 00.\n");
				testc00();
				break ;
			default :
				printf("Requested day %i is still not tested.\n", days[i]);
				break ;

		}
		i += 1;
	}
	MU_REPORT();
	return (minunit_fail);
}

