/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:04:53 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/07 12:51:58 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	r = (char *)s;
	while (*r)
	{
		if (*r == c)
			return (r);
		r++;
	}
	if (*r == c)
		return (r);
	return (NULL);
}
