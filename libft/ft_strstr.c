/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:27:12 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/23 19:28:49 by otahirov         ###   ########.fr       */
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

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (*needle == '\0' || ft_strcmp(haystack, needle) == 0)
		return ((char *)haystack);
	while (*haystack && needle[i])
	{
		if (*haystack == needle[i])
			i = ft_logic(haystack, needle, i, &ptr);
		else
		{
			(i == 0) ? (haystack += 0) : (haystack -= i - 1);
			i = 0;
			ptr = NULL;
		}
		haystack++;
	}
	if (needle[i] == '\0')
		return (ptr);
	return (NULL);
}
