/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:42:41 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/25 14:40:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_pow(int a, int pw)
{
	intmax_t	result;

	if (pw == 0)
		return (1);
	result = a;
	while (pw > 1)
	{
		result *= a;
		pw--;
	}
	return (result);
}
