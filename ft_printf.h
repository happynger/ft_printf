/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/01 14:14:50 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <locale.h>
# include "libft.h"
# define INT_F(x) (x == 'i' || x == 'd' || x == 'D' || x == 'o' || x == 'O')
# define INT_F2(x) (x == 'x' || x == 'X' || x == 'u' || x == 'U')
# define CHAR_F(x) (x == 'c' || x == 'C' || x == 's' || x == 'S')
# define REAL_F(x) (x == 'e' || x == 'E' || x == 'f' || x == 'g' || x == 'G')
# define MISC_F(x) (x == 'n' || x == 'p' || x == 'F' || x == 'a' || x == 'A')
# define CONV(x) (INT_F(x) || INT_F2(x) || CHAR_F(x) || REAL_F(x) || MISC_F(x))
# define FLAGS(x) (x == '-' || x == '+' || x == ' ' || x == '0' || x == '#')

void						ft_error(char *msg);
typedef struct				s_printf_table
{
	char					*flag;
	void					(*func)(void);
}							t_printf_table;

typedef union				u_intmods
{
	int						i;
	short int				si;
	unsigned short int		usi;
	long					l;
}							t_intmods;

typedef union				u_floatmods
{
	float					f;
	double					d;
	long double				ld;
}							t_floatmods;

typedef enum				e_length_mod
{
	LONGLONG = 0,
	LONG,
	SHORT,
	SHORTSHORT,

}							t_length_mod;

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
	{false},
	{false},
	{false},
	{false},
	{false},
	{false},
	{false}
};

int							g_precision = 0;

int							g_bytes = 0;

t_printf_table				g_table[] =
{
	{"s", },
	{"S", },
	{"c", },
	{"C", },
	{"i", },
	{"d", },
	{"D", },
	{"u", },
	{"U", },
	{"o", },
	{"O", },
	{"x", },
	{"X", },
	{"e", },
	{"E", },
	{"g", },
	{"G", },
	{"f", },
	{"F", },
	{"a", },
	{"A", },
	{"p", },
	{"n", }
};

#endif
