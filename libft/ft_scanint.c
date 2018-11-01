/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:37:31 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/01 12:50:13 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Makes an int from string of digits
** Stops at the first non digit value
** Takes in address to the pointer to increment throught the string
*/

int		ft_scanint(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(*str));
	while (ft_isdigit(**str) && **str)
	{
		tmp[i++] = **str;
		*str++;
	}
	return (ft_atoi(tmp));
}
