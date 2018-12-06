/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:34:24 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/30 12:45:59 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *data, size_t data_size, size_t new_size)
{
	void	*tmp;
	void	*new_data;

	if (data_size == new_size)
		return (data);
	CHECK_NULL(tmp = ft_memalloc(data_size + 1));
	tmp = ft_memcpy(tmp, data, data_size);
	ft_memdel(&data);
	CHECK_NULL(new_data = ft_memalloc(new_size + 1));
	if (new_size < data_size)
		new_data = ft_memcpy(new_data, tmp, new_size);
	else
		new_data = ft_memcpy(new_data, tmp, data_size);
	ft_memdel(&tmp);
	return (new_data);
}
