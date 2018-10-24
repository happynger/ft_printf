/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:54:05 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:54:55 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strnlen(src, len);
	if (size != len)
		ft_memset(dst + size, '\0', len - size);
	return (ft_memcpy(dst, src, size));
}
