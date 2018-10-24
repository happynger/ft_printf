/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:59:07 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/09 14:30:50 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	void	*ptr;

	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	p = (char *)ptr;
	while (size > 0)
	{
		*p++ = 0;
		size--;
	}
	return (ptr);
}
