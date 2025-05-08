/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:08:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/08 17:29:21 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_printf_bonus(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		counter;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
			flags = ft_parse(++format);
		if(flags.specifier)
		{
			//printspecifier
		}
		else
			counter++;
	}
	va_end(args);
	return (i);
}
