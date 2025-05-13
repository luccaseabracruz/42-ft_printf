/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:52:03 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 13:45:57 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_count(const char *s)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		counter += ft_putchar_count(*s);
		s++;
	}
	return (counter);
}

static size_t	ft_intlen(int nbr)
{
	size_t	counter;

	if (nbr == INT_MIN)
		return (ft_strlen("-2147483648"));
	counter = 1;
	if (nbr < 0)
	{
		counter++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		counter++;
		nbr /= 10;
	}
	return (counter);
}

int	ft_putnbr_count(int nbr)
{
	char	*buffer;
	int		counter;
	size_t	len;

	if (nbr == INT_MIN)
		return (ft_putstr_count("-2147483648"));
	len = ft_intlen(nbr);
	buffer = ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (0);
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr = -nbr;
	}
	while (len > 0 + (buffer[0] == '-'))
	{
		buffer[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	counter = ft_putstr_count(buffer);
	free(buffer);
	return (counter);
}

size_t	ft_unbrlen_base(uintptr_t ptr, char *base)
{
	size_t	base_len;
	size_t	len;

	base_len = ft_strlen(base);
	len = 1;
	while (ptr >= base_len)
	{
		len++;
		ptr /= base_len;
	}
	return (len);
}
