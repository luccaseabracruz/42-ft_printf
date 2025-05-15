/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:46:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/15 15:42:18 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c_bonus(t_flags flags, int arg)
{
	int	counter;

	counter = 1;
	if (flags.width && !flags.minus)
	{
		counter += ft_putwidth(flags.width, ' ');
	}
	if (ft_isprint(arg))
	{
		write(1, &arg, 1);
	}
	if (flags.width && flags.minus)
	{
		counter += ft_putwidth(flags.width, ' ');
	}
	return (counter);
}
