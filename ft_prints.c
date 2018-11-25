/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/24 19:44:18 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FT_ITOA(is_upper) (ft_itoa(input, base, is_upper))

static intmax_t	pulldata(va_list ap)
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
	else
		input = (intmax_t)va_arg(ap, int);
	return (input);
}

char			*print_i(va_list ap, char fg, char *ret, size_t *s)
{
	intmax_t	input;
	int			base;
	char		*str;
	int			ln;

	base = 10;
	if (fg == 'o')
		base = 8;
	else if (fg == 'x' || fg == 'X')
		base = 16;
	else if (fg == 'b')
		base = 2;
	input = pulldata(ap);
	str = (ft_isupper(fg)) ? (FT_ITOA(true)) : (FT_ITOA(false));
	ln = ft_strlen(str);
	g_bytes += ln;
	ft_strappend(ret, str, *s, ln);
	*s += ln;
	ft_strdel(&str);
	return (ret);
}

char			*print_u(va_list ap, char fg, char *ret, size_t *s)
{
	uintmax_t	uinput;
	char		*str;
	int			ln;
	
	if (fg != 'u')
		ft_error("Calls %u\n");
	uinput = (uintmax_t)pulldata(ap);
	str = ft_uitoa(uinput, 10, false);
	ln = ft_strlen(str);
	g_bytes += ln;
	ft_strappend(ret, str, *s, ln);
	*s += ln;
	ft_strdel(&str);
	return (ret);
}

char			*print_p(va_list ap, char fg, char *ret, size_t *s)
{
	void		*ptr;
	char		*str;
	char		*temp;
	intmax_t	nb;

	if (fg != 'p')
		ft_error("Calls %p\n");
	ptr = va_arg(ap, void*);
	nb = (intmax_t)ptr;
	str = ft_itoa(nb, 16, false);
	temp = ft_strjoin("0x", str);
	ft_strdel(&str);
	str = temp;
	nb = ft_strlen(str);
	ft_strappend(ret, str, *s, nb);
	g_bytes += nb;
	*s += nb;
	ft_strdel(&str);
	return (ret);
}

char			*print_s(va_list ap, char fg, char *ret, size_t *s)
{
	char	*str;
	char	c;
	int		ln;

	if (fg == 's')
	{
		str = va_arg(ap, char *);
		ln = ft_strlen(str);
		ft_strappend(ret, str, *s, ln);
		g_bytes += ln;
		*s += ln;
	}
	else if (fg == 'c')
	{
		c = va_arg(ap, int);
		ft_strappend(ret, &c, *s, 1);
		g_bytes += 1;
		*s += 1;
	}
	return (ret);
}
