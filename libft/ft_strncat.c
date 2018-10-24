/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:49:53 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:50:28 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	s1 += ft_strlen(s1);
	while (*s2 && n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = '\0';
	return (ptr);
}
