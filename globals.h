/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:16:12 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/24 19:37:10 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

/*
**	OUTPUTS
*/
char						*print_p(va_list ap, char fg, char *ret, size_t *s);
char						*print_u(va_list ap, char fg, char *ret, size_t *s);
char						*print_i(va_list ap, char fg, char *ret, size_t *s);
char						*print_s(va_list ap, char fg, char *ret, size_t *s);
char						*print_f(va_list ap, char fg, char *ret, size_t *s);

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
