/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:47:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/10 14:56:18 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	pullfloat(va_list ap)
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

static long			afterpointcalc(long double nb)
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

char				*print_f(va_list ap, char fg)
{
	int			iin;
	long double	fin;
	char		*ret;
	char		*str[2];
	long		ln;

	if (fg != 'f' && fg != 'F' && fg != 'e' && fg != 'E')
		return (NULL);
	fin = pullfloat(ap);
	iin = (int)fin;
	fin -= (float)iin;
	ret = ft_itoa((intmax_t)iin, 10, false);
	ln = afterpointcalc(fin);
	if ((g_flags[4] && g_prec == 0) || g_prec > 0)
	{
		str[0] = ft_strjoin(ret, ".");
		iin = (int)(fin * ft_pow(10, (int)ln));
		ft_strdel(&ret);
		str[1] = ft_itoa((intmax_t)iin, 10, false);
		ret = ft_strjoin(str[0], str[1]);
		ft_strdel(&str[1]);
		ft_strdel(&str[0]);
	}
	return (ret);
}

char				*print_m(va_list ap, char fg)
{
	int		*in;
	char	*ret;

	ret = ft_strnew(1);
	if (fg == '%')
		ret[0] = '%';
	else if (fg == 'n')
	{
		in = va_arg(ap, int *);
		*in = g_bytes;
	}
	return (ret);
}

char			*print_p(va_list ap, char fg)
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
	return (str);
}
