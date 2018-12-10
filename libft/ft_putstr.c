/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:00:53 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/10 15:09:28 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putstr(const char *str)
{
	size_t	ln;

	if (!*str || str == NULL)
		return (0);
	ln = ft_strlen(str);
	write(1, str, ln);
	return (ln);
}
