/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnladdend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:59:48 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/15 12:43:40 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	ft_gnladdend(t_gnl **alst, t_gnl *new)
{
	t_gnl		*list;

	list = *alst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
}

