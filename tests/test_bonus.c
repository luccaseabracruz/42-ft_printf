/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:23:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/09 20:19:25 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/libftprintf_bonus.h"
#include <stdio.h>

static void	test_nospecifiers(void);
static void	test_c(void);

#define TEST_PRINTF(format, ...) { \
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
	test_nospecifiers();
	test_c();
	return (0);
}

// NO SPECIFIERS TEST
static void	test_nospecifiers(void)
{
	int	original_ret;
	int	ft_ret;
	
	printf("\n\n1. NO SPECIFIERS TEST\n");
	
	printf("TEST 1.1:\n");
	TEST_PRINTF("Hello world\n");

	printf("TEST 1.2:\n");
	TEST_PRINTF("Hello%% world\n");

	printf("TEST 1.3:\n");
	TEST_PRINTF("\n");

	printf("TEST 1.4:\n");
	TEST_PRINTF("");

	printf("TEST 1.5:\n");
	TEST_PRINTF("Hello world\n", 'Z');
}

//CHAR TESTS (c)
static void	test_c(void)
{
	int	original_ret;
	int	ft_ret;
	
	printf("\n2 CHAR TESTS:\n");

	printf("TEST 2.1:\n");
	TEST_PRINTF("|%c|\n", 'Z');

	printf("TEST 2.2:\n");
	TEST_PRINTF("|%5c|\n", 'Z');
	
	printf("TEST 2.3:\n");
	TEST_PRINTF("|%-5c|\n", 'Z');

	printf("TEST 2.4:\n");
	TEST_PRINTF("|%c|\n", '\0');

	printf("TEST 2.5:\n");
	TEST_PRINTF("|%5c|\n", '\0');

	printf("TEST 2.6:\n");
	TEST_PRINTF("|%5c|\n");
}
