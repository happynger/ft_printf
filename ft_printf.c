/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:04 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/07 14:15:10 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(const char **form)
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

static int	ft_lenmods(char *form)
{
	if (*form == 'l' && form[1] != 'l')
		g_lenmod[0] = true;
	else if (*form == 'l' && form[1] == 'l')
	{
		g_lenmod[1] = true;
		return (1);
	}
	else if (*form == 'h' && form[1] != 'h')
		g_lenmod[2] = true;
	else if (*form == 'h' && form[1] == 'h')
	{
		g_lenmod[3] = true;
		return (1);
	}
	else if (*form == 'L')
		g_lenmod[4] = true;
	else if (*form == 'j')
		g_lenmod[5] = true;
	return (0);
}

static void	multidigitnb(const char **form, bool isfield)
{
	if (isfield)
	{
		g_field = ft_atoi(*form);
		*form += (ft_intlen(g_field) - 1);
	}
	else
	{
		g_prec = ft_atoi(*form);
		*form += (ft_intlen(g_prec) - 1);
	}
}

static void	ft_conv(const char **form, va_list ap)
{
	size_t	ln;
	char	*ret;

	ln = 0;
	ret = ft_strnew(1);
	*form += 1;
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
				post(g_table[ln - 1].func(ap, **form, ret));
}

/*
** Format:
** % [flags] [field_width] [.precision] [length_modifier] convertional_modifier
*/

int			ft_printf(const char *format, ...)
{
	va_list		print;

	va_start(print, format);
	g_bytes = 0;
	while (*format)
	{
		reset_glob();
		if (*format == '%')
			ft_conv(&format, print);
		else if (*format == '{')
			format += color(format);
		else
			g_bytes += ft_putchar(*format);
		format++;
	}
	va_end(print);
	return (g_bytes);
}

/* int main()
{
	ft_printf("%-05d", -42);
	return 0;
} */