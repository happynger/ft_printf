/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:31:03 by otahirov          #+#    #+#             */
/*   Updated: 2018/11/01 12:50:31 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	initiate_list(const int fd, t_gnl **lst)
{
	t_gnl	*list;
	t_gnl	*head;

	list = *lst;
	head = *lst;
	if (list == NULL)
	{
		list = ft_gnlnew(NULL);
		list->fd = fd;
		*lst = list;
	}
	while (list->next && list->fd != fd)
		list = list->next;
	if (list->fd == fd)
		return ;
	ft_gnladdend(&list, ft_gnlnew(NULL));
	*lst = head;
	while (list->next)
		list = list->next;
	list->fd = fd;
}

int		ft_free(char **arr, int ret, char *str_read)
{
	int		i;

	i = 0;
	while (i < 3 && ret != -1)
		ft_strdel(&arr[i++]);
	ft_strdel(&str_read);
	if (ret != -1)
		free(arr);
	arr = NULL;
	return (ret);
}

char	**ft_strsplit_nl(char *str, int bytes_read, t_gnl *list, const int fd)
{
	char	**arr;
	char	*s;
	int		i[2];

	CHECK_NULL(arr = (char **)malloc(3 * sizeof(*arr)));
	MV_FD(list);
	if (list->content)
		list->content = ft_strappend(list->content, str, AA3, bytes_read);
	else
		list->content = ft_strdup(str);
	s = list->content;
	MV_NL(s);
	if ((!*s && bytes_read == BUFF_SIZE) || bytes_read == -1)
	{
		free(arr);
		return (NULL);
	}
	i[0] = s - list->content;
	i[1] = ft_strlen(s + 1);
	arr[0] = ft_strnew(i[0]);
	arr[1] = ft_strnew(i[1]);
	ft_strncpy(arr[1], ++s, i[1]);
	s = list->content;
	ft_strncpy(arr[0], s, i[0] + 1);
	return (arr);
}

int		ft_copy(char ***line, char **arr, t_gnl *list)
{
	char	*s;
	int		i;

	i = 0;
	CHECK_NULL_GNL(s = ft_strnew(ft_strlen(arr[2])));
	while (arr[2][i] && arr[2][i] != '\n')
	{
		s[i] = arr[2][i];
		i++;
	}
	**line = s;
	if (arr[2][i] == '\0' && list->br == 0 && !ft_strcmp(list->content, ""))
		return (0);
	else
	{
		ft_strdel(&list->content);
		list->content = ft_strdup(arr[1]);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			*str_read;
	int				bytes_read;
	char			**str_array;
	static t_gnl	*list[2];

	if (ERR)
		return (-1);
	initiate_list(fd, &list[0]);
	CHECK_NULL_GNL(str_read = ft_strnew(BUFF_SIZE));
	while ((str_array = ft_strsplit_nl(str_read,
		bytes_read = read(fd, str_read, BUFF_SIZE), list[0], fd)) == NULL)
		if (bytes_read == -1)
			return (ft_free(str_array, -1, str_read));
	list[1] = list[0];
	while (list[1]->fd != fd && list[1]->next)
		list[1] = list[1]->next;
	list[1]->br = bytes_read;
	str_array[2] = ft_strnew(BUFF_SIZE);
	if (ft_strcmp(str_array[2], str_array[0]) != 0)
		str_array[2] = ft_strappend(str_array[2], str_array[0], AA1, AA2);
	return (ft_free(str_array, ft_copy(&line, str_array, list[1]), str_read));
}
