/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:44:12 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/19 11:45:21 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	char	*temp;

	if (s)
	{
		temp = ft_strdup(s);
		ft_strcat(temp, "\n");
		ft_putstr_fd(temp, fd);
		ft_strdel(&temp);
	}
}
