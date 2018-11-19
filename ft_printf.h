/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/18 18:51:55 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# define INT_F(x) (x == 'i' || x == 'd' || x == 'o')
# define INT_F2(x) (x == 'x' || x == 'X' || x == 'u')
# define CHAR_F(x) (x == 'c' || x == 's')
# define REAL_F(x) (x == 'e' || x == 'E' || x == 'f' || x == 'g' || x == 'G')
# define MISC_F(x) (x == 'n' || x == 'p' || x == 'F')
# define CONV(x) (INT_F(x) || INT_F2(x) || CHAR_F(x) || REAL_F(x) || MISC_F(x))
# define FLAGS(x) (x == '-' || x == '+' || x == ' ' || x == '0' || x == '#')
# define LENMD(x) (x == 'l' || x == 'll' || x == 'h' || x == 'hh' || x == 'L')
# define LENMOD(x) (LENMD(x) || x == 'j')

void						ft_error(char *msg);

/*
**	OUTPUTS
*/
void						print_p(va_list ap, char fg);
void						print_u(va_list ap, char fg);
void						print_i(va_list ap, char fg);
void						print_s(va_list ap, char fg);
typedef struct				s_printf_table
{
	char					*flag;
	void					(*func)();
}							t_printf_table;

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
	{"c", },
	{"i", },
	{"d", },
	{"u", },
	{"o", },
	{"x", },
	{"X", },
	{"e", },
	{"E", },
	{"g", },
	{"G", },
	{"f", },
	{"F", },
	{"p", },
	{"n", }
};

#endif
