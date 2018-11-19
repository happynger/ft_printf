/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:04 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/18 18:52:31 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_flags(char **form)
{
	if (**form == '-')
		g_flags[0] = true;
	else if (**form == '+')
		g_flags[1] = true;
	else if (**form == '0')
		g_flags[2] = true;
	else if (**form == ' ' && g_flags[2] != true)
		g_flags[3] = true;
	else if (**form == '#')
		g_flags[4] = true;
}

static void	ft_lenmods(char **form)
{
	if (**form == 'l' && **(form + 1) != 'l')
		g_lenmod[0] = true;
	else if (**form == 'l' && **(form + 1) == 'l')
	{
		g_lenmod[1] = true;
		*form++;
	}
	else if (**form == 'h' && **(form + 1) != 'h')
		g_lenmod[2] = true;
	else if (**form == 'h' && **(form + 1) == 'h')
	{
		g_lenmod[3] = true;
		*form++;
	}
	else if (**form == 'L')
		g_lenmod[4] = true;
	else if (**form == 'j')
		g_lenmod[5] = true;
}

static void	ft_conv(char **form, va_list ap)
{
	char	*field;
	size_t	ln;

	ln = 0;
	field = ft_strnew(10);
	while (**form && !CONV(**form))
	{
		if (FLAGS(**form))
			ft_flags(**form);
		else if (**form == '*')
			g_flags[5] = true;
		else if (ft_isdigit(**form) && g_flags[6] != true)
			field[ln++] = **form;
		else if (**form == '.')
			g_flags[6] = true;
		else if (ft_isdigit(**form) && g_flags[6] == true)
			g_precision = ft_scanint(form);
		else if (LENMOD(**form))
			ft_lenmods(form);
		*form++;
	}
	ln = 0;
	if (CONV(**form))
		while (ln < 16)
			if (g_table[ln++].flag == **form)
				g_table[ln - 1].func();
}

/*
** Format:
** % [flags] [field_width] [.precision] [length_modifier] convertional_modifier
*/

int		ft_printf(const char *format, ...)
{
	va_list		print;

	va_start(print, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				ft_putchar('%');
				format++;
				g_bytes++;
			}
			else
				ft_conv(&format, print);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(print);
	return (g_bytes);
}
