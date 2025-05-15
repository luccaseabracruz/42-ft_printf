/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:10 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/15 15:37:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int			ft_handle_print(va_list args, const char type);
int					ft_handleprint_bonus(t_flags flags, va_list args);
static const char	*ft_jump_format(const char *format);

int	ft_printf(const char *format, ...)
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
				counter += ft_handleprint_bonus(flags, args);
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

int	ft_handleprint_bonus(t_flags flags, va_list args)
{
	if (flags.specifier == '%')
		return (write(1, &flags.specifier, 1));
	if (flags.specifier == 'c')
		return (ft_print_c_bonus(flags, va_arg(args, int)));
	else if (flags.specifier == 's')
		return (ft_print_s(args));
	else if (flags.specifier == 'p')
		return (ft_print_p(args));
	else if (flags.specifier == 'd' || flags.specifier == 'i')
		return (ft_print_d(args));
	else if (flags.specifier == 'u')
		return (ft_print_u(args));
	else if (flags.specifier == 'x')
		return (ft_print_hex(args, "0123456789abcdef"));
	else if (flags.specifier == 'X')
		return (ft_print_hex(args, "0123456789ABCDEF"));
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

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		counter;

// 	va_start(args, format);
// 	counter = 0;
// 	while (*format)
// 	{
// 		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
// 		{
// 			format++;
// 			counter += ft_handle_print(args, *format);
// 		}
// 		else
// 		{
// 			counter += write(1, format, 1);
// 		}
// 		format++;
// 	}
// 	return (counter);
// }

// static int	ft_handle_print(va_list args, const char type)
// {
// 	int	counter;

// 	counter = 0;
// 	if (type == '%')
// 		counter += write(1, &type, 1);
// 	else if (type == 'c')
// 		counter += ft_print_c(args);
// 	else if (type == 's')
// 		counter += ft_print_s(args);
// 	else if (type == 'p')
// 		counter += ft_print_p(args);
// 	else if (type == 'd' || type == 'i')
// 		counter += ft_print_d(args);
// 	else if (type == 'u')
// 		counter += ft_print_u(args);
// 	else if (type == 'x')
// 		counter += ft_print_hex(args, "0123456789abcdef");
// 	else if (type == 'X')
// 		counter += ft_print_hex(args, "0123456789ABCDEF");
// 	return (counter);
// }
