/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:48 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/20 17:00:14 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag # 0 : '-'
** flag # 1 : '+'
** flag # 2 : '0'
** flag # 3 : ' '
** flag # 4 : '#'
** flag # 5 : '*' for field_width
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

int							g_precision = 0;

int							g_bytes = 0;

char						*g_result;

t_printf_table				g_table[] =
{
	{'s', &print_s},
	{'c', &print_s},
	{'i', &print_i},
	{'d', &print_i},
	{'u', &print_u},
	{'o', &print_i},
	{'x', &print_i},
	{'X', &print_i},
	{'b', &print_i},
	{'e', &print_f},
	{'E', &print_f},
	{'g', &print_f},
	{'G', &print_f},
	{'f', &print_f},
	{'F', &print_f},
	{'p', &print_p},
	{'n', &print_i}
};
