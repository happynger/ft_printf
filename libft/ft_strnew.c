/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:12:23 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/08 20:04:13 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*s;

	size += 2;
	str = (char *)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	s = str;
	while (size > 0)
	{
		*s++ = '\0';
		size--;
	}
	return (str);
}
