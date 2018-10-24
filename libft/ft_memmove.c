/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:24:06 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/17 19:50:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	if ((uintptr_t)dst < (uintptr_t)src)
		return (ft_memcpy(dst, src, len));
	i = len;
	d = dst;
	s = src;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dst);
}
