/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:14:06 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:14:21 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	char	*d;

	d = dst;
	while (n > 0)
	{
		*d = *(char*)src;
		n--;
		d++;
		src++;
	}
	return (d);
}
