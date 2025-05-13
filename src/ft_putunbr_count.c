/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:17:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 15:04:12 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uintlen(unsigned int nbr)
{
	size_t	len;

	len = 1;
	while (nbr >= 10)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_putunbr_count(unsigned int nbr)
{
	char	*buffer;
	int		counter;
	size_t	len;

	len = ft_uintlen(nbr);
	buffer = ft_calloc(len + 1, sizeof(char));
	while (len > 0)
	{
		buffer[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	counter = ft_putstr_count(buffer);
	free(buffer);
	return (counter);
}
