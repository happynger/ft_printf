/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:31:15 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/11 19:21:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define ERR (fd <= -1 || line == NULL)
# define R1 (str_read)
# define R3 (list[0])
# define AA1 ft_strlen(str_array[2])
# define AA2 ft_strlen(str_array[0])
# define AA3 ft_strlen(list->content)
# define READ_M(arr) { free(arr); arr = NULL; return (NULL); }
# define MV_FD(x) while (x->fd != fd && x->next) x = x->next
# define MV_NL(s) while (*s != '\n' && *s) s++
# define CHECK_EX(s) if (*s) ft_strncpy(arr[1], ++s, i[1])

# ifndef LIBFT_H
#  include "libft.h"
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
