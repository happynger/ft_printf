/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:26:06 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/11 14:15:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char **str, size_t ln, char c)
{
	char	*t;

	if (*str == NULL || ln == 0)
		return (NULL);
	t = ft_strnew(ft_strlen(*str) + ln);
	ft_memset(t, c, ln);
	ft_memcpy(t + ln, *str, ft_strlen(*str));
	ft_strdel(str);
	*str = t;
	return (t);
}
