/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/03 21:00:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buf(t_slist *buffer, long long rb, char *tmp, char **tmp2)
{
	rb = read(buffer->fd, *tmp2, BUFFER_SIZE);
	if (rb != -1)
		(*tmp2)[rb] = '\0';
	if (rb == 0 || rb == -1)
	{
		if (buffer->first == NULL && *tmp == '\0')
		{
			free(tmp);
			return (0);
		}
		if (*tmp != 0)
			slst_addback(buffer, tmp);
		else
			free(tmp);
		return (1);
	}
	else if (ft_strchr(*tmp2, '\n'))
	{
		slst_split(buffer, tmp);
		free(tmp);
		return (1);
	}
	*tmp2 += rb;
	return (-1);
}

static int	read_line(t_slist *buffer)
{
	char		*tmp;
	char		*tmp2;
	int			ret_buf;

	while (1)
	{
		tmp = (char *)malloc(sizeof(char) * buffer->opt_bufs + 1);
		if (tmp == NULL)
			return (0);
		tmp2 = tmp;
		while (1)
		{
			if (tmp2 - tmp >= buffer->opt_bufs)
			{
				slst_addback(buffer, tmp);
				break ;
			}
			ret_buf = read_buf(buffer, 0, tmp, &tmp2);
			if (ret_buf != -1)
				return (ret_buf);
		}
	}
}

char	*get_next_line(int fd)
{
	static t_slist	buffer[MAX_FILES];
	char			*rstr;
	int				buf_size;

	rstr = NULL;
	if (fd < 0 || fd >= MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd].fd = fd;
	buf_size = BUFFER_SIZE;
	if (buf_size <= 1000)
		buffer[fd].opt_bufs = buf_size * 1000;
	else if (buf_size <= 100000)
		buffer[fd].opt_bufs = buf_size * 10;
	else
		buffer[fd].opt_bufs = buf_size ;
	if (read_line(&buffer[fd]))
		slst_bufcat(&rstr, &buffer[fd]);
	return (rstr);
}
