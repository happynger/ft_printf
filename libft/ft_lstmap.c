/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:56:46 by otahirov          #+#    #+#             */
/*   Updated: 2018/09/16 22:27:41 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newl;
	t_list	*temp;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	newl = ft_lstnew(temp->content, temp->content_size);
	temp = NULL;
	lst = lst->next;
	head = newl;
	while (lst)
	{
		temp = f(lst);
		newl->next = ft_lstnew(temp->content, temp->content_size);
		temp = NULL;
		lst = lst->next;
		newl = newl->next;
	}
	return (head);
}
