/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:52:03 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/12 16:04:18 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar_count(int c)
{
    if (c)
    {
        return (write(1, &c, 1));
    }
    return (0);
}

int ft_putstr_count(char *s)
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
