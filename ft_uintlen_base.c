/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:45:45 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/15 13:43:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uintlen_base(unsigned int nbr, char *base)
{
	size_t	len;
	size_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (nbr >= base_len)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}
