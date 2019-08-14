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

void	display_comb(char n1, char n2, char n3)
{
	if (n1 + n2 + n3 != '0' + '1' + '2')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
}

void	print_comb_true(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0' - 1;
	n2 = '1' - 1;
	n3 = '2' - 1;
	while (++n1 <= '7')
	{
		while (++n2 <= '8')
		{
			while (++n3 <= '9')
			{
				if (n1 < n2 && n2 < n3)
				{
					display_comb(n1, n2, n3);
				}
			}
			n3 = '0';
		}
		n2 = '0';
	}
}

MU_TEST(t_print_comb)
{
	mu_assert_string_eq(ob(ft_print_comb), ob(print_comb_true));
}

void	ft_print_comb2_numbers_true(unsigned short n1, unsigned short n2)
{
	char out1;
	char out2;

	if (!(n1 == 0 && n2 == 1))
	{
		out1 = ',';
		write(1, &out1, 1);
		out1 = ' ';
		write(1, &out1, 1);
	}
	out2 = '0' + n1 % 10;
	n1 /= 10;
	out1 = '0' + n1 % 10;
	write(1, &out1, 1);
	write(1, &out2, 1);
	out1 = ' ';
	write(1, &out1, 1);
	out2 = '0' + n2 % 10;
	n2 /= 10;
	out1 = '0' + n2 % 10;
	write(1, &out1, 1);
	write(1, &out2, 1);
}

void	ft_print_comb2_true(void)
{
	unsigned short n1;
	unsigned short n2;

	n1 = 0;
	n2 = 1;
	while (n1 <= 98)
	{
		while (n2 <= 99)
		{
			if (n1 < n2)
			{
				ft_print_comb2_numbers_true(n1, n2);
			}
			n2 += 1;
		}
		n2 = 0;
		n1 += 1;
	}
	n1 = 0;
}

MU_TEST(t_print_comb2)
{
	mu_assert_string_eq(ob(ft_print_comb2), ob(ft_print_comb2_true));	
}


int		ft_check_combn_digits_true(short *digits, int n)
{
	int	x;

	x = n - 1;
	while (x > 0)
	{
		if (digits[x - 1] >= digits[x])
		{
			digits[x] = digits[x - 1];
			return (0);
		}
		x -= 1;
	}
	return (1);
}

void	ft_print_combn_digits_true(short *digits, int n, int isfirst)
{
	int		x;
	char	out;

	x = 0;
	if (!isfirst)
	{
		write(1, ", ", 2);
	}
	while (x < n)
	{
		out = digits[x] + '0';
		write(1, &out, 1);
		x += 1;
	}
}

void	ft_increment_combn_digits_true(short *digits, int n, int current_digit)
{
	digits[current_digit] += 1;
	if (digits[current_digit] == 10)
	{
		digits[current_digit] = 0;
		ft_increment_combn_digits_true(digits, n, current_digit - 1);
	}
	else
	{
		return ;
	}
}

int		ft_sum_combn_digits_true(short *digits, int n)
{
	int		x;
	int		sum;
	int		ten;

	ten = 1;
	sum = 0;
	x = n - 1;
	while (x >= 0)
	{
		sum += ten * digits[x];
		x -= 1;
		ten *= 10;
	}
	return (sum);
}

void	ft_print_combn_true(int n)
{
	short	digits[n];
	short	max_digits[n];
	int		x;
	int		max_sum;
	int		current_sum;

	x = 0;
	while (x < n)
	{
		digits[x] = x;
		max_digits[x] = (10 - n + x);
		x += 1;
	}
	max_sum = ft_sum_combn_digits_true(max_digits, n);
	ft_print_combn_digits_true(digits, n, 1);
	current_sum = 0;
	while (current_sum < max_sum)
	{
		ft_increment_combn_digits_true(digits, n, n - 1);
		if (ft_check_combn_digits_true(digits, n))
		{
			ft_print_combn_digits_true(digits, n, 0);
			current_sum = ft_sum_combn_digits_true(digits, n);
		}
	}
}

MU_TEST(t_print_combn)
{
	mu_assert_string_eq(ob(ft_print_combn), ob(ft_print_combn_true));
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(t_ft_putchar);
	MU_RUN_TEST(t_ft_print_alphabet);
	MU_RUN_TEST(t_ft_print_reverse_alphabet);
	MU_RUN_TEST(t_ft_print_numbers);
	MU_RUN_TEST(t_ft_is_negative);
	MU_RUN_TEST(t_print_comb);
	MU_RUN_TEST(t_putnbr);
	MU_RUN_TEST(t_print_comb2);
	MU_RUN_TEST(t_print_combn);
}

void	testc00()
{

	MU_RUN_SUITE(test_suite);
}

