/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:58:45 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/24 15:09:40 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty(void)
{
	char		*str;

	str = ft_strnew(0);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char		*str;
	const char	*s0;
	int			i;
	size_t		ln;

	if (!s)
		return (NULL);
	ln = 0;
	i = 0;
	while (*s <= 32 && *s)
		s++;
	if (ft_strcmp(s, "") == 0)
		return (ft_empty());
	s0 = s;
	ln = ft_strlen(s);
	while (s[ln] <= 32 && s[ln - 1] > 0)
		ln--;
	str = ft_strnew(ln + 1);
	if (str == NULL)
		return (NULL);
	ln++;
	while (ln-- > 0 && s[i])
		str[i++] = *s0++;
	str[i] = '\0';
	return (str);
}
