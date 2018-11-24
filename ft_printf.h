/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/20 16:24:53 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include "structs.h"
# include "globals.h"
# define INT_F(x) (x == 'i' || x == 'd' || x == 'o')
# define INT_F2(x) (x == 'x' || x == 'X' || x == 'u')
# define CHAR_F(x) (x == 'c' || x == 's')
# define REAL_F(x) (x == 'e' || x == 'E' || x == 'f' || x == 'g' || x == 'G')
# define MISC_F(x) (x == 'n' || x == 'p' || x == 'F' || x == 'b')
# define CONV(x) (INT_F(x) || INT_F2(x) || CHAR_F(x) || REAL_F(x) || MISC_F(x))
# define FLAGS(x) (x == '-' || x == '+' || x == ' ' || x == '0' || x == '#')
# define LENMD(x) (x == 'l' || x == 'h' || x == 'L')
# define LENMOD(x) (LENMD(x) || x == 'j')
# define MAXCOLORLEN 25
# define TABLE_SIZE 17

void						ft_error(char *msg);
int							color(const char *input);
int							ft_printf(const char *format, ...);

#endif
