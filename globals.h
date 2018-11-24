/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:16:12 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/20 17:00:34 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

/*
**	OUTPUTS
*/
void						print_p(va_list ap, char fg);
void						print_u(va_list ap, char fg);
void						print_i(va_list ap, char fg);
void						print_s(va_list ap, char fg);
void						print_f(va_list ap, char fg);

# define G_LENMOD 6
# define G_FLAGS 7

extern bool				g_flags[];
extern bool				g_lenmod[];
extern int				g_precision;
extern int				g_bytes;
extern char				*g_result;
extern t_printf_table	g_table[];

#endif
