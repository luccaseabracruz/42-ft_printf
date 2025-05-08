/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:08:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/08 15:25:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_printf_bonus(const char *format, ...)
{
	va_list	args;
	int		i;
	int		s_counter;

	va_start(args, format);
	i = 0;
	s_counter = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			s_counter++;
			format++; 
		}
		i += write(1, format++, 1);
	}
	write(1, "\n", 1);
	ft_putnbr_fd(s_counter, 1);
	va_end(args);
	return (i);
}
