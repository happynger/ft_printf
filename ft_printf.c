/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:08:04 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/23 18:39:30 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(char **form)
{
	
}

int		ft_printf(const char *format, ...)
{
	va_list		print;
	char		*form;

	form = format;
	va_start(print, format);
	while (*form)
	{
		if (*form == '%')
		{
			if (*(form + 1) == '%')
				ft_putchar('%');
			else
				ft_flags(&form);
		}
		else
			ft_putchar(*form);
		form++;
	}
	va_end(print);
}
