/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/12/06 15:28:26 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include "structs.h"

# define INT_F(x) (x == 'i' || x == 'd' || x == 'o')
# define INT_F2(x) (x == 'x' || x == 'X' || x == 'u')
# define CHAR_F(x) (x == 'c' || x == 's')
# define REAL_F(x) (x == 'f')
# define MISC_F(x) (x == 'n' || x == 'p' || x == 'F' || x == 'b' || x == '%')
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
# define INIT_LENMOD(x) else if (LENMOD(**x)) *x += ft_lenmods((char *)*x)
# define INIT_CONV(x) if (CONV(**x)) g_conv = **x
# define INIT_TEMP(t) else t = ft_strdup("")

# define ADD_O(t) if (g_conv == 'o') t = ft_strdup("0")
# define ADD_XS(t) else if (g_conv == 'x') t = ft_strdup("0x")
# define ADD_X(t) else if (g_conv == 'X') t = ft_strdup("0X")
# define ADD_F(t) else if (ALLR(g_conv)) t = ft_strdup(".")
# define ADD_N(t) else t = ft_strdup("")
# define ADD_P(t, r) if (NEG(r, 1)) t = ft_strdup("+")
# define ADD_S(t, r) else if (NEG(r, 3)) t = ft_strdup(" ")
# define ADD_NE(t) else t = ft_strdup("-")

# define SKIPTOC(x, c, i) while (x[i] != c && x[i]) i++

# define MAXCOLORLEN 25
# define TABLE_SIZE 14

void						ft_error(char *msg);
int							color(const char *input);
void						post(char *ret);
int							ft_printf(const char *format, ...);
void						reset_glob(void);
/*
**	OUTPUTS
*/
char						*print_p(va_list ap, char fg, char *ret);
char						*print_u(va_list ap, char fg, char *ret);
char						*print_i(va_list ap, char fg, char *ret);
char						*print_s(va_list ap, char fg, char *ret);
char						*print_f(va_list ap, char fg, char *ret);
char						*print_m(va_list ap, char fg, char *ret);

# define G_LENMOD 6
# define G_FLAGS 7

extern bool				g_flags[];
extern bool				g_lenmod[];
extern int				g_prec;
extern int				g_field;
extern int				g_bytes;
extern char				g_conv;
extern t_printf_table	g_table[];

#endif
