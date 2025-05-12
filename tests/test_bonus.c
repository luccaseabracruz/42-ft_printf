/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:23:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/12 15:42:49 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/ft_printf_bonus.h"
#include <stdio.h>

static void	test_nospecifiers(void);
static void	test_c(void);
static void test_s(void);

#define TEST_PRINTF_BONUS(format, ...) { \
    int original_ret = printf(format, ##__VA_ARGS__); \
    int ft_ret = ft_printf_bonus(format, ##__VA_ARGS__); \
    if (original_ret == ft_ret) { \
        printf("[OK] - Expected and Actual Match \\o/\n\n"); \
    } else { \
        printf("[!!!BOOOOOOOOOM!!!] - Mismatch: Expected %d, Got %d\n\n", original_ret, ft_ret); \
    } \
}

int	main(void)
{
	// test_nospecifiers();
	// test_c();
	test_s();
	return (0);
}

// NO SPECIFIERS TEST
static void	test_nospecifiers(void)
{
	printf("\n\n1. NO SPECIFIERS TEST\n");
	
	printf("TEST 1.1:\n");
	TEST_PRINTF_BONUS("Hello world\n");

	printf("TEST 1.2:\n");
	TEST_PRINTF_BONUS("Hello%% world\n");

	printf("TEST 1.3:\n");
	TEST_PRINTF_BONUS("\n");

	printf("TEST 1.4:\n");
	TEST_PRINTF_BONUS("");

	printf("TEST 1.5:\n");
	TEST_PRINTF_BONUS("Hello world\n", 'Z');
}


//CHAR TESTS (c)
static void	test_c(void)
{	
	printf("\n2 CHAR TESTS:\n");

	printf("TEST 2.1:\n");
	TEST_PRINTF_BONUS("|%c|\n", 'Z');

	printf("TEST 2.2:\n");
	TEST_PRINTF_BONUS("|%5c|\n", 'Z');
	
	printf("TEST 2.3:\n");
	TEST_PRINTF_BONUS("|%-5c|\n", 'Z');

	printf("TEST 2.4:\n");
	TEST_PRINTF_BONUS("|%c|\n", '\0');

	printf("TEST 2.5:\n");
	TEST_PRINTF_BONUS("|%5c|\n", '\0');

	printf("TEST 2.6:\n");
	TEST_PRINTF_BONUS("|%5c|\n");
}

//STRING TESTS (s)
static void test_s(void)
{
	printf("\n3. STRING TESTS\n");
	
	printf("TEST 3.1:");
	TEST_PRINTF("\n");
}
