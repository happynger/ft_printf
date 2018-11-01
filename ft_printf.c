/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:04 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/01 14:13:07 by otahirov         ###   ########.fr       */
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
	else if (**form == ' ' && g_flags[1] != true)
		g_flags[3] = true;
	else if (**form == '#')
		g_flags[4] = true;
}

static void	ft_conv(char **form)
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
		*form++;
	}
	ln = 0;
	if (CONV(**form))
		while (ln < 23)
			if (g_table[ln++].flag == **form)
				g_table[ln - 1].func();
}

static void ft_locale()
{
	static int	reverse;

	if (reverse == false)
	{
		setlocale(LC_ALL, "UTF-8");
		reverse = true;
	}
	else
	{
		setlocale(LC_ALL, NULL);
		reverse = false;
	}
}

void		ft_error(char *msg)
{
	if (msg != NULL)
		ft_putstr(msg);
	exit(1);
}

/*
** Format:
** % [flags] [field_width] [.precision] [length_modifier] convertional_modifier
*/

int		ft_printf(const char *format, ...)
{
	va_list		print;

	va_start(print, format);
	ft_locale();
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
				ft_conv(&format);
		}
		else
			ft_putchar(*format);
		format++;
	}
	ft_locale();
	va_end(print);
	return (g_bytes);
}
