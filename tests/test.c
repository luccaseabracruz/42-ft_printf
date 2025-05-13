/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:23:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 12:35:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"
#include <stdio.h>

static void	test_nospecifiers(void);
static void	test_c(void);
static void test_s(void);
static void test_p(void);
static void test_d(void);

#define TEST_PRINTF(format, ...) { \
    int original_ret = printf(format, ##__VA_ARGS__); \
    int ft_ret = ft_printf(format, ##__VA_ARGS__); \
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
	// test_s();
	// test_p();
	test_d();
	return (0);
}

// NO SPECIFIERS TEST
static void	test_nospecifiers(void)
{
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
	printf("\n2. CHAR TESTS:\n");

	printf("TEST 2.1:\n");
	TEST_PRINTF("|%c|\n", 'Z');
}

static void test_s(void)
{
	printf("\n3. STRING TESTS\n");
	
	printf("TEST 3.1:\n");
	TEST_PRINTF("\n");

	printf("TEST 3.2:\n");
	TEST_PRINTF("%s\n", NULL);
}

static void test_p(void)
{
	printf("\n4. POINTER TESTS\n");
	
	int	x = 0;
	printf("TEST 4.1:");
	TEST_PRINTF("%p\n", &x);
}

static void test_d(void)
{
	printf("\n5. INTEGER TESTS\n");
	ft_printf("|%d|", -101);
	
	printf("TEST 5.1:\n");
	TEST_PRINTF("%d\n", 42);
	
	printf("TEST 5.2:\n");
	TEST_PRINTF("%d\n", -101);
	
	printf("TEST 5.2:\n");
	TEST_PRINTF("%d\n");
	
	printf("TEST 5.3:\n");
	TEST_PRINTF("%i\n", 42);
	
	printf("TEST 5.4:\n");
	TEST_PRINTF("%i\n", -101);
	
	printf("TEST 5.5:\n");
	TEST_PRINTF("%i\n");

	printf("TEST 5.6:\n");
	TEST_PRINTF("%d\n", NULL);

	printf("TEST 5.7:\n");
	TEST_PRINTF("%i\n", NULL);
}
