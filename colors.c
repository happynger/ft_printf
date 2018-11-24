/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:25:46 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/23 16:56:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print(char *clr)
{
	g_bytes += ft_putchar('{');
	g_bytes += ft_putstr(clr);
	g_bytes += ft_putchar('}');
}

static void		choose_bold_color(char *clr)
{
	if (!ft_strcmp(clr, "bold_red") || !ft_strcmp(clr, "bold red"))
		ft_putstr("\033[1;31m");
	else if (!ft_strcmp(clr, "bold_green") || !ft_strcmp(clr, "bold green"))
		ft_putstr("\033[1;32m");
	else if (!ft_strcmp(clr, "bold_yellow") || !ft_strcmp(clr, "bold yellow"))
		ft_putstr("\033[1;33m");
	else if (!ft_strcmp(clr, "bold_blue") || !ft_strcmp(clr, "bold blue"))
		ft_putstr("\033[1;34m");
	else if (!ft_strcmp(clr, "bold_magenta") || !ft_strcmp(clr, "bold magenta"))
		ft_putstr("\033[1;35m");
	else if (!ft_strcmp(clr, "bold_cyan") || !ft_strcmp(clr, "bold cyan"))
		ft_putstr("\033[1;36m");
	else
		print(clr);
}

static void		choose_color(char *clr)
{
	int		i;

	i = 0;
	while (clr[i])
	{
		clr[i] = ft_tolower(clr[i]);
		i++;
	}
	if (!ft_strcmp(clr, "red"))
		ft_putstr("\033[0;31m");
	else if (!ft_strcmp(clr, "green"))
		ft_putstr("\033[0;32m");
	else if (!ft_strcmp(clr, "yellow"))
		ft_putstr("\033[0;33m");
	else if (!ft_strcmp(clr, "blue"))
		ft_putstr("\033[0;34m");
	else if (!ft_strcmp(clr, "magenta"))
		ft_putstr("\033[0;35m");
	else if (!ft_strcmp(clr, "cyan"))
		ft_putstr("\033[0;36m");
	else if (!ft_strcmp(clr, "0") || !ft_strcmp(clr, ""))
		ft_putstr("\033[0m");
	else
		choose_bold_color(clr);
}

int				color(const char *input)
{
	const char	*in;
	char		*clr;
	int			i;

	in = input;
	i = 0;
	clr = ft_strnew(ft_strlenc(in, '}'));
	if (*in == '{')
		in++;
	while (*in && *in != '}')
		clr[i++] = *in++;
	in++;
	clr[i] = '\0';
	choose_color(clr);
	ft_strdel(&clr);
	return (in - input - 1);
}
