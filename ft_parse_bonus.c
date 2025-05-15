/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:37:12 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/15 15:42:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero_pad = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = 0;
	flags.precision.key = 0;
	flags.precision.value = 0;
	flags.specifier = 0;
	return (flags);
}

static void	ft_parse_flags(t_flags *flags, const char **format)
{
	while (ft_strchr("#0+- ", **format))
	{
		if (**format == '#')
		{
			flags->hash = 1;
		}
		else if (**format == '0')
		{
			flags->zero_pad = 1;
		}
		else if (**format == '+')
		{
			flags->plus = 1;
		}
		else if (**format == '-')
		{
			flags->minus = 1;
		}
		else if (**format == ' ')
		{
			flags->space = 1;
		}
		(*format)++;
	}
}

static void	ft_parse_width(t_flags *flags, const char **format)
{
	flags->width = ft_atoi(*format);
	while (ft_isdigit(**format))
	{
		(*format)++;
	}
}

static void	ft_parse_precision(t_flags *flags, const char **format)
{
	if (**format == '.')
	{
		flags->precision.key = 1;
		flags->precision.value = ft_atoi(++(*format));
		while (ft_isdigit(**format))
		{
			(*format)++;
		}
	}
}

t_flags	ft_parse_bonus(const char *format)
{
	t_flags	flags;

	flags = initialize_flags();
	ft_parse_flags(&flags, &format);
	ft_parse_width(&flags, &format);
	ft_parse_precision(&flags, &format);
	if (ft_strchr("cspdiuxX%", *format))
	{
		flags.specifier = *format;
	}
	return (flags);
}
