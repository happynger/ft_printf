/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:09:18 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/15 12:45:17 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_gnl	*ft_gnlnew(char const *content)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	if (content == NULL)
	{
		new->content = NULL;
		return (new);
	}
	new->content = (char *)malloc(ft_strlen(content));
	if (new->content == NULL)
		return (NULL);
	ft_memcpy(new->content, content, ft_strlen(content));
	return (new);
}

