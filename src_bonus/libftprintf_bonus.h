/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:33:13 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/08 15:16:14 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>

# define SPECIFIERS = "cspdiuxX%"
# define HEX_UPPER = "0123456789ABCDEF"
# define HEX_LOWER = "0123456789abcdef"

typedef	struct	s_flags
{
	int	minus;
	int	zero_pad;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

int	ft_printf_bonus(const char *format, ...);

#endif