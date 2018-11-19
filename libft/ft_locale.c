/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:20:01 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/01 15:03:14 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <locale.h>
#include <stdarg.h>

void	ft_locale(const char *new_locale,
					void (*subroutine)(),
					va_list ap, char flag)
{
	char	*old_locale;
	char	*saved_locale;

	old_locale = setlocale(LC_ALL, NULL);
	saved_locale = ft_strdup(old_locale);
	if (saved_locale == NULL)
		ft_error("Out of Memory");
	setlocale(LC_ALL, new_locale);
	(*subroutine)(ap, flag);
	setlocale(LC_ALL, saved_locale);
	free(saved_locale);
}
