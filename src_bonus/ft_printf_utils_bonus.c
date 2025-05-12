/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:15:06 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/12 15:36:57 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putwidth(int width, char c)
{
	int	counter;

	counter = 0;
	while (--width > 0)
	{
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}
