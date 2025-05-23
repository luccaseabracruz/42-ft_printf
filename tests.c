/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:45:18 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/23 22:48:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>

#define TEST(fmt, ...) \
    do { \
        int ret1 = printf(fmt, __VA_ARGS__); \
        int ret2 = ft_printf(fmt, __VA_ARGS__); \
        printf(" [ret: %d | ft_ret: %d]\n", ret1, ret2); \
    } while (0)

int	main(void)
{
    TEST("%c\n", 'Z');
    TEST("%s\n", "string");
    TEST("%d\n", 5);
    TEST("%p\n", (void *)"test");
    TEST("%d\n", 0);
    TEST("%d\n", -5);
    TEST("%d\n", INT32_MAX);
    TEST("%d\n", INT32_MIN);
    TEST("%i\n", 42);
    TEST("%u\n", 42U);
    TEST("%u\n", UINT32_MAX);
    TEST("%x\n", 255);
    TEST("%X\n", 255);
    return 0;
}