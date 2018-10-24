/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:16 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:15:36 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void			*p;
	int				i;

	p = ft_memchr(src, c, n);
	i = 0;
	if (p != NULL)
		return (ft_mempcpy(dst, src, (p - src + 1)));
	ft_memcpy(dst, src, n);
	return (NULL);
}
