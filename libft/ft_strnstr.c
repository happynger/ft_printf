/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:17:47 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/24 14:43:23 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_logic(const char *haystack,
			const char *needle, int i, char **ptr)
{
	if (*haystack == needle[0] && *ptr == NULL)
		*ptr = (char *)haystack;
	i++;
	return (i);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && needle[i] && len > 0)
	{
		if (*haystack == needle[i])
			i = ft_logic(haystack, needle, i, &ptr);
		else if (i != 0 && *haystack != needle[i])
		{
			(i == 0) ? (haystack += 0) : (haystack -= i - 1);
			(i == 0) ? (i += 0) : (len += i - 1);
			i = 0;
			ptr = NULL;
		}
		haystack++;
		len--;
	}
	if (needle[i] == '\0')
		return (ptr);
	return (NULL);
}
