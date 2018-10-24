/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:43:45 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/16 22:30:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*str;
	const char		*st;

	if (!s)
		return (NULL);
	i = 0;
	st = s;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	st += start;
	while (len-- > 0)
	{
		str[i] = st[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
