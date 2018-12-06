/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:41:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/06 13:00:45 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Field Width is the min field for the var
**	Precision is how many numbers are after . in floats
**	!!! PLUS SHOULD BE CHECKED BY FIELD!
*/

static void	precf(char **ret)
{
	int		i;
	int		ln;
	char	*t[2];

	i = 0;
	SKIPTOC(*ret, '.', i);
	i++;
	ln = (int)ft_strlen(*ret + i);
	if (ln < g_prec)
	{
		ln = g_prec - ln;
		t[0] = ft_strnew(ln);
		ft_memset(t[0], '0', ln);
	}
	else
	{
		ln = g_prec;
		t[0] = ft_strdup(*ret + i);
		t[0][ln] += ((t[0][ln + 1] - '0') >= 5) ? (1) : (0);
		*ret = ft_realloc(*ret, ft_strlen(*ret), (size_t)i);
	}
	t[1] = ft_strnjoin(*ret, t[0], ln);
	ft_strdel(&t[0]);
	ft_strdel(ret);
	*ret = t[1];
}

static void	field(char **ret, char sign)
{
	int		ln;
	char	c;
	char	*str;
	char	*t;

	ln = (int)ft_strlen(*ret);
	if (ln > g_field)
		return ;
	ln = g_field - ln;
	str = ft_strnew(ft_strlen(*ret) + ln + 1);
	c = (g_flags[2] && !g_flags[0]) ? ('0') : (' ');
	str = (char *)ft_memset(str, c, ln);
	if (g_flags[0])
		t = ft_strjoin(*ret, str);
	else
		t = ft_strjoin(str, *ret);
	if (sign)
		t[0] = sign;
	ft_strdel(&str);
	ft_strdel(ret);
	*ret = t;
}

static void	flags(char **ret, char *sign)
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
		ADD_P(t[1], *ret);
		ADD_S(t[1], *ret);
		ADD_NE(t[1]);
	}
	INIT_TEMP(t[1]);
	t[2] = (ALLR(g_conv)) ? ft_strcat(*ret, t[0]) : ft_strjoin(t[0], *ret);
	*sign = *t[1];
	ft_strdel(&t[0]);
	ft_strdel(&t[1]);
	ft_strdel(ret);
	*ret = t[2];
}

void		prec(char **ret)
{
	int		ln;
	char	*t[2];

	if (g_prec == 6)
		return ;
	if ((ln = ft_strlen(*ret)) > g_prec)
		ft_memset(*ret + g_prec, 0, (ln - g_prec));
	else if (ln < g_prec && g_conv == 'o')
	{
		t[0] = ft_strnew(g_prec - ln);
		ft_memset(t[0], '0', (g_prec - ln));
		t[1] = ft_strjoin(t[0], *ret);
		ft_strdel(&t[0]);
		ft_strdel(ret);
		*ret = t[1];
	}
}

void		post(char *ret)
{
	char	sign;

	flags(&ret, &sign);
	if (REAL_F(g_conv) || g_conv == 'F')
		precf(&ret);
	else
		prec(&ret);
	field(&ret, sign);
	g_bytes += ft_putstr(ret);
	ft_strdel(&ret);
}
