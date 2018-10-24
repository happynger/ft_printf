/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:07:23 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/27 14:39:52 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				res;
	int				sign;

	if (*str == '\0' || *str == '\e')
		return (0);
	while (*str <= ' ' && *str != '\200')
		str++;
	res = 0;
	sign = 1;
	if (str[0] == '-')
	{
		str++;
		sign = -1;
	}
	else if (str[0] == '+')
		str++;
	while (*str)
	{
		if (*str - '0' > 9)
			break ;
		res = ((res * 10) + (*str - '0'));
		str++;
	}
	return (res * sign);
}
