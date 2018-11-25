/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:04 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/24 20:12:42 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_flags(const char **form)
{
	if (**form == '-')
		g_flags[0] = true;
	else if (**form == '+')
		g_flags[1] = true;
	else if (**form == '0')
		g_flags[2] = true;
	else if (**form == ' ')
		g_flags[3] = true;
	else if (**form == '#')
		g_flags[4] = true;
}

static void	ft_lenmods(const char **form)
{
	if (**form == 'l' && **(form + 1) != 'l')
		g_lenmod[0] = true;
	else if (**form == 'l' && **(form + 1) == 'l')
	{
		g_lenmod[1] = true;
		*form += 1;
	}
	else if (**form == 'h' && **(form + 1) != 'h')
		g_lenmod[2] = true;
	else if (**form == 'h' && **(form + 1) == 'h')
	{
		g_lenmod[3] = true;
		*form += 1;
	}
	else if (**form == 'L')
		g_lenmod[4] = true;
	else if (**form == 'j')
		g_lenmod[5] = true;
}

static void	ft_conv(const char **form, va_list ap)
{
	size_t	ln;
	size_t	size;
	char	*ret;

	ln = 0;
	size = 0;
	ret = ft_strnew(size + 1);
	while (**form && !CONV(**form))
	{
		INIT_FLAGS(form);
		INIT_VARFIELD(form, ap);
		INIT_FIELD(form);
		INIT_DOT(form);
		INIT_VARPREC(form, ap);
		INIT_PREC(form);
		INIT_LENMOD(form);
		*form += 1;
	}
	ln = 0;
	INIT_CONV(form);
	if (CONV(**form))
		while (ln < TABLE_SIZE)
			if (g_table[ln++].flag == **form)
				post(g_table[ln - 1].func(ap, **form, ret, &size));
}

static void	reset_glob(void)
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

/*
** Format:
** % [flags] [field_width] [.precision] [length_modifier] convertional_modifier
*/

int		ft_printf(const char *format, ...)
{
	va_list		print;

	va_start(print, format);
	reset_glob();
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				g_bytes += ft_putchar('%');
				format++;
			}
			else
				ft_conv(&format, print);
		}
		else if (*format == '{')
			format += color(format);
		else
			g_bytes += ft_putchar(*format);
		format++;
	}
	va_end(print);
	return (g_bytes);
}
