/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:41:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/30 13:29:33 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Field Width is the min field for the var
**	Precision is how many numbers are after . in floats
**	!!! PLUS SHOULD BE CHECKED BY FIELD!
*/

static char	*precf(char *ret)
{
	int		i;
	int		ln;
	char	*t;

	i = 0;
	SKIPTOC(ret, '.', i);
	i++;
	ln = (int)ft_strlen(ret + i);
	if (ln < g_prec)
	{
		ln = g_prec - ln;
		CHECK_NULL((t = ft_strnew(ln)));
		ft_memset(t, '0', ln);
	}
	else
	{
		ln = g_prec;
		t = ft_strdup(ret + i);
		t[ln] += ((t[ln + 1] - '0') >= 5) ? (1) : (0);
		ret = ft_realloc(ret, ft_strlen(ret), (size_t)i);
	}
	ret = ft_strnjoin(ret, t, ln);
	ft_strdel(&t);
	return (ret);
}

static char	*field(char *ret, char sign)
{
	int		ln;
	char	c;
	char	*str;
	char	*t;

	ln = (int)ft_strlen(ret);
	if (ln > g_field)
		return (ret);
	ln = g_field - ln;
	CHECK_NULL((str = ft_strnew(ft_strlen(ret) + ln + 1)));
	c = (g_flags[2] && !g_flags[0]) ? ('0') : (' ');
	str = (char *)ft_memset(str, c, ln);
	if (g_flags[0])
		t = ft_strjoin(ret, str);
	else
		t = ft_strjoin(str, ret);
	if (sign)
		t[0] = sign;
	ft_strdel(&str);
	return (t);
}

static char	*flags(char *ret, char *sign)
{
	char	*t[3];

	if (g_flags[4])
	{
		ADD_O(t[0]);
		ADD_XS(t[0]);
		ADD_X(t[0]);
		ADD_F(t[0]);
		ADD_N(t[0]);
	}
	INIT_TEMP(t[0]);
	if ((g_conv != 's' || g_conv != 'c') && (g_flags[1] || g_flags[3]))
	{
		ADD_P(t[1], ret);
		ADD_S(t[1], ret);
		ADD_NE(t[1]);
	}
	INIT_TEMP(t[1]);
	t[2] = (ALLR(g_conv)) ? ft_strcat(ret, t[0]) : ft_strjoin(t[0], ret);
	*sign = *t[1];
	ft_strdel(&t[0]);
	ft_strdel(&t[1]);
	return (t[2]);
}

char		*prec(char *ret)
{
	int		ln;
	char	*t;

	if (g_prec == 6)
		return (ret);
	if ((ln = ft_strlen(ret)) > g_prec)
		ft_memset(ret + g_prec, 0, (ln - g_prec));
	else if (ln < g_prec && g_conv == 'o')
	{
		CHECK_NULL((t = ft_strnew(g_prec - ln)));
		ft_memset(t, '0', (g_prec - ln));
		ft_strjoin(t, ret);
	}
	return (ret);
}

void		post(char *ret)
{
	char	sign;

	ret = flags(ret, &sign);
	if (REAL_F(g_conv) || g_conv == 'F')
		ret = precf(ret);
	else
		ret = prec(ret);
	ret = field(ret, sign);
	g_bytes += ft_putstr(ret);
	ft_strdel(&ret);
}
