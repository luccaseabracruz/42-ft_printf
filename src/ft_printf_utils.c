/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:52:03 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 00:36:09 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar_count(int c)
{
    return (write(1, &c, 1));
}

int ft_putstr_count(const char *s)
{
    int counter;

    counter = 0;
    while (*s)
    {
        counter += ft_putchar_count(*s);
        s++;
    }
    return (counter);
}

size_t  ft_nbrlen_base(uintptr_t ptr, char *base)
{
    size_t  base_len;
    size_t  len;

    base_len = ft_strlen(base);
    len = 0;
    while (ptr >= base_len)
    {
        len++;
        ptr /= base_len;
    }
    return (++len);
}
