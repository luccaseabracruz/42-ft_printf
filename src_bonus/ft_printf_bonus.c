/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:08:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/09 16:12:08 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int					ft_handleprint(t_flags flags, va_list args);
static const char	*ft_jump_format(const char *format);

int	ft_printf_bonus(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		counter;

	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = ft_parse_bonus(format);
			if (flags.specifier)
			{
				counter += ft_handleprint(flags, args);
				format = ft_jump_format(format);
			}
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (counter);
}

int	ft_handleprint(t_flags flags, va_list args)
{
	if (flags.specifier == '%')
	{
		return (write(1, &flags.specifier, 1));
	}
	if (flags.specifier == 'c')
		return (ft_print_c_bonus(flags, va_arg(args, int)));
	return (0);
}

static const char	*ft_jump_format(const char *format)
{
	while (ft_strchr("-0.# +", *format) || ft_isdigit(*format))
	{
		format++;
	}
	return (format);
}
