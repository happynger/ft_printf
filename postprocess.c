/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:41:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/24 20:16:00 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Field Width is the min field for the var
**	Precision is how many numbers are after . in floats
**	!!! PLUS SHOULD BE CHECKED BY FIELD!
*/

static char	*prec(char *ret)
{
	int		i;
	int		ln;
	char	*t;

	i = 0;
	SKIPTOC(ret, '.', i);
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
	ret = ft_strjoin(ret, t);
	ft_strdel(&t);
	return (ret);
}

static char	*field(char *ret)
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
	c = (g_flags[2]) ? ('0') : (' ');
	str = (char *)ft_memset(str, c, ln);
	if (g_flags[0])
		t = ft_strjoin(ret, str);
	else
		t = ft_strjoin(str, ret);
	ft_strdel(&str);
	return (t);
}

static char	*flags(char *ret)
{
	char	*t[3];

	if (g_flags[4])
	{
		ADD_O(t[0]);
		ADD_x(t[0]);
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
	ret = ft_strjoin(t[1], t[2]);
	ft_strdel(&t[2]);
	ft_strdel(&t[0]);
	ft_strdel(&t[1]);
	return (ret);
}

void		post(char *ret)
{
	ret = flags(ret);
	if (REAL_F(g_conv) || g_conv == 'F')
		ret = prec(ret);
	ret = field(ret);
	ft_putstr(ret);
	ft_strdel(&ret);
}
