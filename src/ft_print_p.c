/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:21:25 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 01:09:22 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_p(va_list args)
{
    uintptr_t   arg;
    size_t      len;
    size_t      base_len;
    char        *buffer;
    int         ret;

    arg = (uintptr_t)va_arg(args, void *);
    if (!arg)
        return (ft_putstr_count("(nil)"));
    base_len = ft_strlen("0123456789abcdef");
    len = ft_nbrlen_base(arg, "0123456789abcdef") + 2;
    buffer = ft_calloc(len, sizeof(char));
    if (!buffer)
        return (0);
    ft_strlcpy(buffer, "0x", 3);
    while (--len > 1)
    {
        buffer[len] = "0123456789abcdef"[arg % base_len];
        arg /= base_len;
    }
    ret = ft_putstr_count((const char *)buffer);
    free(buffer);
    return (ret);
}
