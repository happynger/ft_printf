/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 10:39:40 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 12:41:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_d(char const *s, char c)
{
	size_t	ln;

	ln = 0;
	while (s[ln] != c && s[ln])
		ln++;
	return (ln);
}

static size_t	ft_arrlen(char const *s, char c)
{
	size_t	ln;

	ln = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*(s + 1) == c && *(s + 1))
				s++;
			if (*(s + 1))
				ln++;
		}
		s++;
	}
	return (ln);
}

static int		ft_logic(char const *s, char c, char **strarray, int *i)
{
	int		b;
	char	*temp;
	int		l;

	b = 0;
	l = 0;
	temp = ft_strnew(ft_strlen_d(s, c));
	if (temp == NULL)
		return (l);
	while (*s != c && *s)
	{
		temp[b++] = *s++;
		l++;
	}
	strarray[*i] = temp;
	*i += 1;
	while (*s == c && *s)
	{
		s++;
		l++;
	}
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**strarray;
	int			i;
	int			b;

	b = 0;
	if (!s)
		return (NULL);
	i = 0;
	strarray = (char **)malloc((ft_arrlen(s, c) + 1) * sizeof(*strarray));
	if (strarray == NULL)
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		b = ft_logic(s, c, strarray, &i);
		if (b != 0)
			s += b;
		else
			return (NULL);
	}
	strarray[i] = NULL;
	return (strarray);
}
