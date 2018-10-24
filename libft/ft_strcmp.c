/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:20:22 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/14 14:03:09 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (*st1 && *st2)
	{
		if (*st1 - *st2 != 0)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 - *st2 != 0)
		return (*st1 - *st2);
	return (0);
}
