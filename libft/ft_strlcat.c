/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:49:47 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:50:42 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		dlen;
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	i = dstsize;
	while (i-- != 0 && *d)
		d++;
	dlen = d - dst;
	i = (dstsize - dlen);
	if (i == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
