/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:53:33 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/23 17:11:13 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s);
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
