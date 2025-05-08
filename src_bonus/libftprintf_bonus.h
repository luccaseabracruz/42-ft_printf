/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:33:13 by lseabra-          #+#    #+#             */
/*   Updated: 2025/05/08 18:38:39 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct s_key_value
{
	int		key;
	char	*value;
}	t_key_value;

typedef struct s_flags
{
	int			minus;
	int			zero_pad;
	int			hash;
	int			space;
	int			plus;
	int			width;
	t_key_value	precision;
	int			specifier;
}	t_flags;

int		ft_printf_bonus(const char *format, ...);
t_flags	ft_parse(const char *format);

#endif