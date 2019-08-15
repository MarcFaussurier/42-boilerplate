/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c03.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 13:34:29 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 12:58:40 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../includes/ob.h"
#include "../libs/minunit/minunit.h"
#include "../includes/c04.h"



MU_TEST(t_ft_strlen)
{
	mu_assert(ft_strlen("avion") == strlen("avion"), "error in strlen");
	mu_assert(ft_strlen("bonjour") == strlen("bonjour"), "error in strlen");
	mu_assert(ft_strlen("avio") != strlen("avion"), "error in strlen");
	mu_assert(ft_strlen("") == strlen(""), "error in strlen");
}

void	testputstr()
{
	ft_putstr("Hello world potetos ~#$%");
	ft_putstr("I am an othere one \n");
	ft_putstr("");
}

void	trueputstr()
{
	printf("Hello world potetos ~#$%%");
	printf("I am an othere one \n");
	write(1, "", 0);
}

MU_TEST(t_ft_putstr)
{
	mu_assert_string_eq(ob(trueputstr), ob(testputstr));
}

void	trueputnbr()
{
	printf("%li", -2147483648);
	printf("%i", -42);
	printf("%i", 0);
	printf("%i", 9865);
	printf("\n");
}

void	testputnbr()
{
	ft_putnbr(-2147483648);
	ft_putnbr(-42);
	ft_putnbr(0);
	ft_putnbr(9865);
	write(1, "\n", 1);
}

MU_TEST(t_ft_putnbr)
{
	mu_assert_string_eq(ob(trueputnbr), ob(testputnbr));
}

void	trueatoi()
{
	printf("%i", atoi("-2147483648"));
	printf("%i", atoi("-42"));
	printf("%i", atoi("0"));
	printf("%i", atoi("9865"));
	printf("\n");
}

void	testatoi()
{
	printf("%i", ft_atoi("-2147483648"));
	printf("%i", ft_atoi("-42"));
	printf("%i", ft_atoi("0"));
	printf("%i", ft_atoi("9865"));
	printf("\n");
}

MU_TEST(t_ft_atoi)
{
	mu_assert_string_eq(ob(trueatoi), ob(testatoi));
}


void	testputnbrbase()
{
	char *hex		=  "0123456789ABCDEF";
	char *decimal	= "0123456789";
	char *poney		= "poney vif";

	ft_putnbr_base(-2147483648, hex);
	ft_putnbr_base(-2147483648, decimal);
	ft_putnbr_base(-2147483648, poney);
	write(1, "\n", 1);
	ft_putnbr_base(-42, hex);
	ft_putnbr_base(-42, decimal);
	ft_putnbr_base(-42, poney);
	write(1, "\n", 1);
	ft_putnbr_base(0, hex);
	ft_putnbr_base(0, decimal);
	ft_putnbr_base(0, poney);
	write(1, "\n", 1);
	ft_putnbr_base(9865, hex);
	ft_putnbr_base(9865, decimal);
	ft_putnbr_base(9865, poney);
	write(1, "\n", 1);
}

void	trueputnbrbase()
{
	printf("-80000000-2147483648- yifiievin\n-2A-42-yv\n00p\n26899865oyyio\n");
}

MU_TEST(t_ft_putnbr_base)
{
	printf("%s\n", ob(trueputnbrbase));
	mu_assert_string_eq(ob(trueputnbrbase), ob(testputnbrbase));
}

MU_TEST(t_ft_atoi_base)
{
	char	buffer1[1500];
	char	buffer2[1500];

	char *hex		=  "0123456789ABCDEF";
	char *decimal	= "0123456789";
	char *poney		= "poney vif";

	sprintf(buffer2, "-2147483648-2147483648-2147483648\n-42-42-42\n000\n986598659865\n");
	sprintf(buffer1, "%i%i%i\n%i%i%i\n%i%i%i\n%i%i%i\n", 
			ft_atoi_base("-80000000", hex),
			ft_atoi_base("-2147483648", decimal),
			ft_atoi_base("- yifiievin", poney),
			ft_atoi_base("-2A", hex),
			ft_atoi_base("-42", decimal),
			ft_atoi_base("-yv", poney),
			ft_atoi_base("0", hex),
			ft_atoi_base("0", decimal),
			ft_atoi_base("p", poney),
			ft_atoi_base("2689", hex),
			ft_atoi_base("9865", decimal),
			ft_atoi_base("oyyio", poney)
			);
	
	mu_assert_string_eq(buffer2, buffer1);
}

MU_TEST_SUITE(test_suite_4)
{
	MU_RUN_TEST(t_ft_strlen);
	MU_RUN_TEST(t_ft_putstr);
	MU_RUN_TEST(t_ft_putnbr);
	MU_RUN_TEST(t_ft_atoi);
	MU_RUN_TEST(t_ft_putnbr_base);
	MU_RUN_TEST(t_ft_atoi);
	MU_RUN_TEST(t_ft_atoi_base);
}

void	testc04()
{

	MU_RUN_SUITE(test_suite_4);
}

