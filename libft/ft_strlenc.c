/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:47:20 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/23 16:53:38 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *str, const char c)
{
	size_t	ln;

	ln = 0;
	while (str[ln] && str[ln] != c)
		ln++;
	return (ln);
}
