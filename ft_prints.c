/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/06 16:32:07 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FT_ITOA(is_upper) (ft_itoa(input, base, is_upper))
#define FT_UITOA(is_upper) (ft_uitoa(uinput, base, is_upper))

static intmax_t		pulldata(va_list ap)
{
	intmax_t		input;
	short int		si;
	unsigned char	uc;

	if (g_lenmod[0])
		input = (intmax_t)va_arg(ap, long);
	else if (g_lenmod[1])
		input = (intmax_t)va_arg(ap, long long);
	else if (g_lenmod[2])
	{
		si = (short int)va_arg(ap, int);
		input = (intmax_t)si;
	}
	else if (g_lenmod[3])
	{
		uc = (unsigned int)va_arg(ap, int);
		input = (intmax_t)uc;
	}
	else if (g_lenmod[5])
		input = va_arg(ap, intmax_t);
	else
		input = (intmax_t)va_arg(ap, int);
	return (input);
}

static uintmax_t	pulludata(va_list ap)
{
	uintmax_t				input;
	unsigned short int		si;
	unsigned char			uc;

	if (g_lenmod[0])
		input = (uintmax_t)va_arg(ap, unsigned long);
	else if (g_lenmod[1])
		input = (uintmax_t)va_arg(ap, unsigned long long);
	else if (g_lenmod[2])
	{
		si = (unsigned short int)va_arg(ap, int);
		input = (uintmax_t)si;
	}
	else if (g_lenmod[3])
	{
		uc = (unsigned int)va_arg(ap, int);
		input = (uintmax_t)uc;
	}
	else if (g_lenmod[5])
		input = va_arg(ap, uintmax_t);
	else
		input = (uintmax_t)va_arg(ap, unsigned int);
	return (input);
}

char				*print_i(va_list ap, char fg, char *ret)
{
	intmax_t	input;
	int			base;
	char		*str;
	int			ln;

	base = 10;
	if (fg == 'b')
		base = 2;
	input = pulldata(ap);
	str = (ft_isupper(fg)) ? (FT_ITOA(true)) : (FT_ITOA(false));
	ln = ft_strlen(str);
	ret = ft_strappend(ret, str, 1, ln);
	ft_strdel(&str);
	return (ret);
}

char				*print_u(va_list ap, char fg, char *ret)
{
	uintmax_t	uinput;
	char		*str;
	int			ln;
	int			base;

	base = 10;
	if (fg == 'o')
		base = 8;
	else if (fg == 'x' || fg == 'X')
		base = 16;
	uinput = pulludata(ap);
	if (uinput == 0)
	{
		g_flags[4] = false;
		if (g_prec == 0 || (g_prec == 6 && g_flags[6]))
		{
			g_flags[2] = false;
			return (ret);
		}
	}
	str = (ft_isupper(fg)) ? (FT_UITOA(true)) : (FT_UITOA(false));
	ln = ft_strlen(str);
	ret = ft_strappend(ret, str, 1, ln);
	ft_strdel(&str);
	return (ret);
}

char			*print_s(va_list ap, char fg, char *ret)
{
	char	*str;
	char	c;
	int		ln;

	if (fg == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = ft_strdup("(null)");
		ln = ft_strlen(str);
		ret = ft_strappend(ret, str, 1, ln);
	}
	else if (fg == 'c')
	{
		c = va_arg(ap, int);
		if (c == 0)
		{
			ret = ft_strappend(ret, "^@", 1, 2);
			g_bytes -= 1;
			g_field += 1;
		}
		else
			ret[0] = c;
	}
	return (ret);
}
