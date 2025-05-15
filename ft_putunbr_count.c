/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:17:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/13 17:32:22 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_count(unsigned int nbr)
{
	char	*buffer;
	int		counter;
	size_t	len;

	len = ft_uintlen_base(nbr, "0123456789");
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
