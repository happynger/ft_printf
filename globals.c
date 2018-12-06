/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:48 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/06 15:37:40 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag # 0 : '-'
** flag # 1 : '+'
** flag # 2 : '0'
** flag # 3 : ' '
** flag # 4 : '#'
** flag # 5 : EMPTY
** flag # 6 : '.' for precision
*/

bool						g_flags[] =
{
	false,
	false,
	false,
	false,
	false,
	false,
	false
};

/*
**	lenmod # 0 : 'l'
**	lenmod # 1 : 'll'
**	lenmod # 2 : 'h'
**	lenmod # 3 : 'hh'
**	lenmod # 4 : 'L'
**	lenmod # 5 : 'j'
*/

bool						g_lenmod[] =
{
	false,
	false,
	false,
	false,
	false,
	false
};

int							g_prec = 0;

int							g_bytes = 0;

int							g_field = 0;

char						g_conv = 0;

t_printf_table				g_table[] =
{
	{'s', &print_s},
	{'c', &print_s},
	{'i', &print_i},
	{'d', &print_i},
	{'u', &print_u},
	{'o', &print_u},
	{'x', &print_u},
	{'X', &print_u},
	{'b', &print_i},
	{'f', &print_f},
	{'F', &print_f},
	{'p', &print_p},
	{'%', &print_m},
	{'n', &print_m}
};

void	reset_glob(void)
{
	int		i;

	i = 0;
	g_bytes = 0;
	g_prec = 6;
	g_conv = 0;
	g_field = 0;
	while (i < G_LENMOD)
		g_lenmod[i++] = false;
	i = 0;
	while (i < G_FLAGS)
		g_flags[i++] = false;
}
