/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:26:08 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/29 09:26:06 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(long i)
{
	char	*str;
	int		nb;

	str = ft_itoa((intmax_t)i, 10, false);
	nb = ft_putstr(str);
	ft_strdel(&str);
	return (nb);
}
