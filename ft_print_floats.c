/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:47:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/25 14:32:02 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern bool g_flags[];
extern bool g_lenmod[];

static long double	pullFloat(va_list ap)
{
	long double		input;

	if (g_lenmod[0])
		input = (long double)va_arg(ap, double);
	else if (g_lenmod[4])
		input = va_arg(ap, long double);
	else
		input = (long double)va_arg(ap, double);
	return (input);
}

static long			afterpointCalc(long double nb)
{
	long		ln;
	int			inb;

	inb = (int)nb;
	ln = 0;
	while ((nb - (long double)inb) > 0)
	{
		nb *= 10;
		ln++;
		inb = (int)nb;
		if (ln >= g_prec * 2)
			break ;
	}
	return (ln);
}

#include <stdio.h>

char				*print_f(va_list ap, char fg, char *ret, size_t *s)
{
	int			iIn;
	long double	fIn;
	char		*str[2];
	long		ln;

	if (fg != 'f' && fg != 'F' && fg != 'e' && fg != 'E')
		return (NULL);
	fIn = pullFloat(ap);
	iIn = (int)fIn;
	fIn -= (float)iIn;
	ret = ft_itoa((intmax_t)iIn, 10, false);
	ln = afterpointCalc(fIn);
	if ((g_flags[4] && g_prec == 0) || g_prec > 0)
	{
		str[0] = ft_strjoin(ret, ".");
		iIn = (int)(fIn * ft_pow(10, (int)ln));
		ft_strdel(&ret);
		str[1] = ft_itoa((intmax_t)iIn, 10, false);
		ret = ft_strjoin(str[0], str[1]);
		*s += ft_strlen(ret);
		ft_strdel(&str[1]);
		ft_strdel(&str[0]);
	}
	return (ret);
}
