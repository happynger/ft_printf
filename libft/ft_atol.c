/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:07:23 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/10 13:33:08 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atol(const char *str)
{
	intmax_t		res;
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
	while (*str && ft_isdigit(*str))
	{
		res = ((res * 10) + (*str - '0'));
		str++;
	}
	return (res * sign);
}
