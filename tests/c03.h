/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c03.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 13:34:29 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 12:24:03 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../libs/minunit/minunit.h"
#include "../includes/c03.h"


MU_TEST(t_ft_strcmp)
{
	mu_assert(ft_strcmp("abcd", "abcde") ==  strcmp("abcd", "abcde"), "strncmp compares pas n");
	mu_assert(ft_strcmp("abc", "abe") ==  strcmp("abc", "abe"), "strncmp fails to compare n-1st first");
}


MU_TEST(t_ft_strncmp)
{
	mu_assert(ft_strncmp("abcd", "abcde", 3) ==  0, "strncmp compares pas n");
	mu_assert(ft_strncmp("abc", "abe", 3) ==  -2, "strncmp fails to compare n-1st first");
	mu_assert(ft_strncmp("abcd", "pabcde", 0) ==  0, "strncmp compares pas n");
}

MU_TEST(t_ft_strcat)
{
	char b[32];
	strcpy(b, "abc");
	mu_assert_string_eq(ft_strcat(b, "123456"), "abc123456");
	mu_assert(b[9] == 0, "strcat dont fill with trailling nop");
}

MU_TEST(t_ft_strncat)
{
	char b[32];
	char c[32];
	strcpy(b, "abc");
	strcpy(c, "abc");
	mu_assert_string_eq(strncat(b, "123456", 3), ft_strncat(c, "123456", 3));
	mu_assert(b[6] == c[6] && b[6] == 0, "error missing trailling null");
	strcpy(b, "abc");
	strcpy(c, "abc");
	mu_assert_string_eq(strncat(b, "123456", 0), ft_strncat(c, "123456", 0));
	strcpy(b, "abc");
	strcpy(c, "abc");
	mu_assert_string_eq(strncat(b, "123456", 12), ft_strncat(c, "123456", 12));
}

MU_TEST(t_ft_strstr)
{
	mu_assert_string_eq(strstr("avion", "vi"), ft_strstr("avion", "vi"));
	mu_assert_string_eq(strstr("abcd", "a"), ft_strstr("abcd", "a"));
	mu_assert_string_eq(strstr("avion", ""), ft_strstr("avion", ""));
	mu_assert_string_eq(strstr("", "vi"), ft_strstr("", "vi"));
}

MU_TEST(t_ft_strlcat)
{
	char b[33];
	char c[33];
	char	buffer[255];
	char	buffer2[255];

	memcpy(b, "abc\0\0\0x\0", 8);
	memcpy(c, "abc\0\0\0x\0", 8);
	sprintf(buffer, "%u", ft_strlcat(c, "123", 6));
	sprintf(buffer2, "%lu", strlcat(b, "123", 6));
	mu_assert_string_eq(buffer2, buffer);

	memcpy(b, "abc\0\0\0x\0", 8);
	memcpy(c, "abc\0\0\0x\0", 8);
	sprintf(buffer, "%u", ft_strlcat(c, "123", 4));
	sprintf(buffer2, "%lu", strlcat(b, "123", 4));
	mu_assert_string_eq(buffer2, buffer);

	memcpy(b, "abc\0\0\0x\0", 8);
	memcpy(c, "abc\0\0\0x\0", 8);
	sprintf(buffer, "%u", ft_strlcat(c, "123", 8));
	sprintf(buffer2, "%lu", strlcat(b, "123", 8));
	mu_assert_string_eq(buffer2, buffer);

	memcpy(b, "abc\0\0\0x\0", 8);
	memcpy(c, "abc\0\0\0x\0", 8);
	sprintf(buffer, "%u", ft_strlcat(c, "123", 8));	
	sprintf(buffer2, "%lu", strlcat(b, "123", 8));
	mu_assert_string_eq(buffer2, buffer);
	
	memcpy(b, "im", 8);
	memcpy(c, "a str", 8);
	int got = ft_strlcat(b, c, 7);
	sprintf(buffer, "%u", got);
	
	memcpy(b, "im", 8);
	memcpy(c, "a str", 8);
	int ori = strlcat(b, c, 7);
	sprintf(buffer2, "%u", ori);
	mu_assert_string_eq(buffer2, buffer);
	mu_assert(ori == got, "error in strlcat return statement");
	
	memcpy(b, "abc\0\0\0x\0", 8);
	memcpy(c, "abc\0\0\0x\0", 8);
	sprintf(buffer, "%u", ft_strlcat(c, "123", 3));
	sprintf(buffer2, "%lu", strlcat(b, "123", 3));
	mu_assert_string_eq(buffer2, buffer);
}

MU_TEST_SUITE(test_suite_3)
{
	MU_RUN_TEST(t_ft_strcmp);
	MU_RUN_TEST(t_ft_strncmp);
	MU_RUN_TEST(t_ft_strcat);
	MU_RUN_TEST(t_ft_strncat);
	MU_RUN_TEST(t_ft_strstr);
	MU_RUN_TEST(t_ft_strlcat);
}

void	testc03()
{

	MU_RUN_SUITE(test_suite_3);
}

