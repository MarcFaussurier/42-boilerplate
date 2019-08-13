#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../libs/minunit/minunit.h"
#include "../includes/ob.h"
#include "../includes/c00.h"


void	test_ft_putchar()
{
	char c;

	c = 0;
	while (1)
	{
		c += 1;
		ft_putchar(c);
		if (c == 127)
			break ;
	}
	//write(1, "o", 1);
}
void	true_function()
{
	char c;

	c = 0;
	while (1)
	{
		c += 1;
		write(1, &c, 1);
		if (c == 127)
			break ;
	}
}
MU_TEST(t_ft_putchar) 
{
	char	*exp;
	char	*got;

	exp = ob(true_function);
	got = ob(test_ft_putchar);
	mu_assert_string_eq(exp, got);
}
MU_TEST(t_ft_print_alphabet)
{
	mu_assert_string_eq(ob(ft_print_alphabet), "abcdefghijklmnopqrstuvwxyz");
}

MU_TEST(t_ft_print_reverse_alphabet)
{
	mu_assert_string_eq(ob(ft_print_reverse_alphabet), "zyxwvutsrqponmlkjihgfedcba" );
}

MU_TEST(t_ft_print_numbers)
{
	mu_assert_string_eq(ob(ft_print_numbers), "0123456789");
}


void	isnegative()
{
	ft_is_negative(42);
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_is_negative(-2147483648);
	ft_is_negative(2147483647);
}

void	isnegative_true()
{
	printf("PPNNP");
}

MU_TEST(t_ft_is_negative)
{
	mu_assert_string_eq(ob(isnegative), ob(isnegative_true));
}

void	putnbr()
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-1);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
}

void	putnbr_true()
{
	printf("%i\n", 42);
	printf("%i\n", 0);
	printf("%i\n", -1);
	printf("%li\n", -2147483648);
	printf("%i", 2147483647);
}

MU_TEST(t_putnbr)
{
	mu_assert_string_eq(ob(putnbr), ob(putnbr_true));
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(t_ft_putchar);
	MU_RUN_TEST(t_ft_print_alphabet);
	MU_RUN_TEST(t_ft_print_reverse_alphabet);
	MU_RUN_TEST(t_ft_print_numbers);
	MU_RUN_TEST(t_ft_is_negative);
	MU_RUN_TEST(t_putnbr);
}

void	testc00()
{

	MU_RUN_SUITE(test_suite);
}

