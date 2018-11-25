/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/25 13:35:12 by otahirov         ###   ########.fr       */
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
# define ALLR(x) ((REAL_F(x) || x == 'F') && g_prec == 0)
# define NEG(x, i) ((ft_atoi(x) >= 0) && g_flags[i])

# define CHK_DIGIT(x) (ft_isdigit(**x) && g_flags[6] == false && g_field == 0)
# define CHK_DGIT(x) (ft_isdigit(**x) && g_flags[6] == true && g_prec == 6)
# define CHK_FLAGS(r) if (!g_flags[1] && !g_flags[3] && !g_flags[4]) return (r)

# define INIT_FLAGS(x) if (FLAGS(**x)) ft_flags(x)
# define INIT_VARFIELD(x, ap) else if (**x == '*') g_field = va_arg(ap, int)
# define INIT_FIELD(x) else if (CHK_DIGIT(x)) multidigitnb(x, true)
# define INIT_DOT(x) else if (**x == '.') g_flags[6] = true
# define INIT_VARPREC(x, ap) else if (**x == '*') g_prec = va_arg(ap, int)
# define INIT_PREC(x) else if (CHK_DGIT(x)) multidigitnb(x, false)
# define INIT_LENMOD(x) else if (LENMOD(**x)) ft_lenmods(x)
# define INIT_CONV(x) if (CONV(**x)) g_conv = **x
# define INIT_TEMP(t) else t = ft_strdup("")

# define ADD_O(t) if (g_conv == 'o') t = ft_strdup("0")
# define ADD_x(t) else if (g_conv == 'x') t = ft_strdup("0x")
# define ADD_X(t) else if (g_conv == 'X') t = ft_strdup("0X")
# define ADD_F(t) else if (ALLR(g_conv)) t = ft_strdup(".")
# define ADD_N(t) else t = ft_strdup("")
# define ADD_P(t, r) if (NEG(r, 1)) t = ft_strdup("+")
# define ADD_S(t, r) else if (NEG(r, 3)) t = ft_strdup(" ")
# define ADD_NE(t) else t = ft_strdup("-")

# define SKIPTOC(x, c, i) while (x[i] != c && x[i]) i++

# define MAXCOLORLEN 25
# define TABLE_SIZE 17

void						ft_error(char *msg);
int							color(const char *input);
void						post(char *ret);
int							ft_printf(const char *format, ...);
void						reset_glob(void);

#endif
