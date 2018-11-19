/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/18 18:44:35 by otahirov         ###   ########.fr       */
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
	return (input);
}

void			print_i(va_list ap, char fg)
{
	intmax_t	input;
	int			base;
	char		*str;

	base = 10;
	if (fg == 'o')
		base = 8;
	else if (fg == 'x' || fg == 'X')
		base = 16;
	else if (fg == 'b')
		base = 2;
	input = pulldata(ap);
	str = (ft_isupper(fg)) ? (FT_ITOA(true)) : (FT_ITOA(false));
	g_bytes += ft_putstr(str);
	ft_strdel(&str);
}

void			print_u(va_list ap, char fg)
{
	uintmax_t	uinput;
	
	if (fg != 'u')
		ft_error("Calls %u\n");
	uinput = (uintmax_t)pulldata(ap);
	g_bytes += ft_putnbr((long)uinput);
}

void			print_p(va_list ap, char fg)
{
	void	*ptr;
	char	*str;
	long	nb;

	if (fg != 'p')
		ft_error("Calls %p\n");
	ptr = va_arg(ap, void*);
	nb = (long)ptr;
	str = ft_itoa((intmax_t)nb, 16, false);
	g_bytes += ft_putstr("0x");
	g_bytes += ft_putstr(str);
	ft_strdel(&str);
}

void			print_s(va_list ap, char fg)
{
	char	*str;
	char	c;

	if (fg == 's')
	{
		str = va_arg(ap, char *);
		g_bytes += ft_putstr(str);
	}
	else if (fg == 'c')
	{
		c = va_arg(ap, int);
		g_bytes += ft_putchar(c);
	}
}
