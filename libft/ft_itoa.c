/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:42:37 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 12:39:24 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_logic(char *str, int i, long long *l, t_bool *isnegative)
{
	if (*l == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (i);
	}
	if (*l < 0)
	{
		*isnegative = TRUE;
		*l = -*l;
	}
	return (i);
}

char			*ft_itoa(int nb)
{
	t_bool		isnegative;
	int			i;
	long long	l;
	int			rem;
	char		*str;

	l = nb;
	str = ft_strnew(ft_intlen(l));
	if (str == NULL)
		return (NULL);
	isnegative = FALSE;
	i = ft_logic(str, 0, &l, &isnegative);
	while (l != 0)
	{
		rem = l % 10;
		str[i++] = (rem + '0');
		l = l / 10;
	}
	if (isnegative == TRUE)
		str[i++] = '-';
	str[i] = '\0';
	ft_reverse(str);
	return (str);
}
