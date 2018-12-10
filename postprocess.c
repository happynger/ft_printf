/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:41:30 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/10 13:35:31 by otahirov         ###   ########.fr       */
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

static void	field(char **ret, char sign, char c)
{
	int		ln;
	char	*str;
	char	*t[2];

	t[1] = *ret;
	if (sign && CHK_SIGN(g_flags) && ft_strchr(t[1], sign) == NULL)
		ft_strshift(&t[1], 1, sign);
	if (sign && CHK_FIELD(t[1]) && g_flags[2] && !g_flags[0])
		t[1]++;
	ln = (int)ft_strlen(t[1]);
	if (ln > g_field)
	{
		*ret = t[1];
		return ;
	}
	ln = g_field - ln;
	str = ft_strnew(ft_strlen(t[1]) + ln + 1);
	str = (char *)ft_memset(str, c, ln);
	if (g_flags[0])
		t[0] = ft_strjoin(t[1], str);
	else
		t[0] = ft_strjoin(str, t[1]);
	if (sign && CHK_RESIGN(g_flags) && ft_strchr(t[0], sign) == NULL)
		t[0][0] = sign;
	ft_strdel(&str);
	*ret = t[0];
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
	if ((CHK_S) || (g_flags[2] && ft_strchr(*ret, '-') != NULL))
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
	if ((ln = ft_strlen(*ret)) > g_prec && CHAR_F(g_conv))
		ft_memset(*ret + g_prec, 0, (ln - g_prec));
	else if (ln <= g_prec && (INT_F(g_conv) || INT_F2(g_conv)))
	{
		t[0] = ft_strnew(g_prec - ln);
		ft_memset(t[0], '0', (g_prec - ln));
		t[1] = ft_strjoin(t[0], *ret);
		if (ft_strchr(t[1], '-'))
		{
			*ft_strchr(t[1], '-') = '0';
			ft_strshift(&t[1], 1, '-');
		}
		ft_strdel(&t[0]);
		ft_strdel(ret);
		*ret = t[1];
	}
}

void		post(char *ret)
{
	char	sign;
	char	c;

	c = (g_flags[2] && !g_flags[0]) ? ('0') : (' ');	
	flags(&ret, &sign);
	if (REAL_F(g_conv) || g_conv == 'F')
		precf(&ret);
	else
		prec(&ret);
	field(&ret, sign, c);
	if (INT_F2(g_conv) && g_flags[2] && g_flags[4] && !g_flags[0])
	{
		ret[0] = '0';
		ret[1] = (g_conv == 'x') ? 'x' : 'X';
	}
	else if (INT_F2(g_conv) && g_flags[2] && g_flags[4] && g_flags[0])
	{
		ft_strshift(&ret, 2, '0');
		ret[1] = (g_conv == 'x') ? 'x' : 'X';
		(g_flags > 0) ? (ret[g_field] = '\0') : (ret[0] = '0');
	}
	g_bytes += ft_putstr(ret);
}
