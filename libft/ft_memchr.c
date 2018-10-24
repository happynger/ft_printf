/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:24:45 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/16 22:28:34 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cs;
	char	ch;

	cs = (char *)s;
	ch = c;
	while (n > 0)
	{
		if (*cs == ch)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
