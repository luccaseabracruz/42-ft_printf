/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:23:41 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 14:59:28 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"
#include <stdio.h>

static void	test_nospecifiers(void);
static void	test_c(void);
static void test_s(void);
static void test_p(void);
static void test_d(void);
static void	test_u(void);

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
	// test_d();
	test_u();
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

//STRING TESTS (s)
static void test_s(void)
{
	printf("\n3. STRING TESTS\n");
	
	printf("TEST 3.1:\n");
	TEST_PRINTF("\n");

	printf("TEST 3.2:\n");
	TEST_PRINTF("%s\n", NULL);
}

//POINTER TESTS (p)
static void test_p(void)
{
	printf("\n4. POINTER TESTS\n");
	
	int	x = 0;
	printf("TEST 4.1:");
	TEST_PRINTF("%p\n", &x);
}

//DECIMAL TESTS (d)
static void test_d(void)
{
	printf("\n5. INTEGER TESTS\n");
	
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

//UNSIGNED DECIMAL TESTS (u)
static void	test_u(void)
{
	printf("\n6. UNSIGNED INTEGER TESTS\n");
	ft_printf("%u\n", INT_MIN);
	
	printf("TEST 6.1:\n");
	TEST_PRINTF("%u\n", -1);
	
	printf("TEST 6.2:\n");
	TEST_PRINTF("%u\n", -101);
	
	printf("TEST 6.3:\n");
	TEST_PRINTF("%u\n", INT_MIN);
	
	printf("TEST 6.4:\n");
	TEST_PRINTF("%u\n", INT_MIN);
	
	printf("TEST 6.5:\n");
	TEST_PRINTF("%u\n", LONG_MAX);
	
	printf("TEST 6.6:\n");
	TEST_PRINTF("%u\n", UINT_MAX);
	
	printf("TEST 6.7:\n");
	TEST_PRINTF("%u\n", ULONG_MAX);
	
	printf("TEST 6.8:\n");
	TEST_PRINTF("%u\n", 9223372036854775807LL);
	
	printf("TEST 6.9:\n");
	TEST_PRINTF("%u\n", ULONG_MAX);
	
	printf("TEST 6.10:\n");
	TEST_PRINTF("%u\n", 0);
}
